#include <algorithm>
#include <vector>
#include <cstddef>
#include <iostream>


static void print(std::vector<int>& A) {
    std::cout << "[ ";
    for(auto a : A)
        std::cout << a << " ";
    std:: cout << "]" << std::endl;
}

int solution(std::vector<int> &A) {
    std::size_t size = A.size();
    std::size_t idx=0;
    int lowest = A[idx++];
    int highest = lowest;
    while(idx<size) {
        highest = A[idx++];
        while(idx < size && highest <= lowest) {
            auto tmp = A[idx++];
            if(tmp > highest)
                highest = tmp;
        }

        if(idx == size) {
            break;
        }

        if(highest < lowest) {
            auto tmp = lowest;
            lowest = highest;
            highest = tmp;
        }
    }

    if(highest<lowest)

    if(highest-lowest > 1)
        return lowest+1;

    if(highest-lowest == 1 || lowest == highest)
        return highest+1;

    // otherwise default to 1
    return 1;
}


static bool assert_true(int a,int b) {
    if(a == b) return true;

    std::cout << "expected " << b << " got " << a << std::endl;

    return false;
}

#define TEST(A,B) print(A); assert(assert_true(solution(A),B)) 

int main(int argc, char ** argv) 
{
    std::vector<int> ar;
    
    ar = {1,2,3,4};
    TEST(ar,5);

    ar = {-4,1,-2,-3,5};
    TEST(ar,2);

    ar = {-2,1,-3,2,5};
    TEST(ar,3);

    ar = {1, 3, 6, 4, 1, 2};
    TEST(ar,5);

    ar = {0, 0, 0, -1, -1, -2};
    TEST(ar,1);

    ar = {-1,-1,-2,1};
    TEST(ar,2);

    ar = {1,2};
    TEST(ar,3);

    ar = {-1,-3};
    TEST(ar,1);

    ar = {-1};
    TEST(ar,1);

    ar = {0};
    TEST(ar,1);

    ar = {10};
    TEST(ar,11);

    ar = {1,3};
    TEST(ar,2);

    ar = {1};
    TEST(ar,2);

    ar = {2};
    TEST(ar,3);

    ar = {2,2,2,2,2,-1,-1,-1};
    TEST(ar,3);
}