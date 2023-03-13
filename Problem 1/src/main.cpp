#include <algorithm>
#include <vector>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>

int solution(std::vector<int> &A, std::vector<int>& B, int N) 
{

    auto size = A.size();
    std::vector<std::set<int>> connected;

    // In order to make the vector readable and simplify the code
    // we sacrifice entry 0
    connected.resize(size+1);
    
    // put it all in a data structure
    for(int i=0;i<size;i++) {
        connected[A[i]].insert(B[i]);
        connected[B[i]].insert(A[i]);
    }

    // To find the limit of connectivity, we travel backwards 
    // to nodes that have a value less than the starting point
    // The vector guarantees that we have ordered all nodes 1 to N
    int count = 0;
    int last = 0;
    for(auto start = N; start>=0; start--) {
        for(auto a : connected[start]) {
            if(a < start) 
                count++;
        }
        if(last == count)
            break;
        last = count;
    }   

    return count;
}


static bool assert_true(int a,int b) {
    if(a == b) return true;

    std::cout << "expected " << b << " got " << a << std::endl;

    return false;
}

#define TEST(A,B,N,R) assert(assert_true(solution(A,B,N),R))


// These are the only test cases that I remember from the problem
int main(int argc, char ** argv) 
{
    std::vector<int> ar1;
    std::vector<int> ar2;
    
    ar1 = {1,2,3,4};
    ar2 = {2,3,1,3};
    TEST(ar1,ar2,4,4);

    ar1 = {1,2,3,4,5,6};
    ar2 = {2,3,2,5,4,5}; 
    TEST(ar1,ar2,6,2);

    return 0;
}