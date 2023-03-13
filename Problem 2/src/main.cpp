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

std::vector<int> solution(std::vector<int> &A) {
    // We need to create a structure that records the
    // frequency of integers 
    std::vector<int> freq;

    // First get the highest value
    int highest = 0;
    for(auto i : A) 
        if(i > highest)
            highest = i;

    // now count the frequency of all numbers in the array
    // which are guaranteed to be non zero positive integers.
    // We sacrifice entry 0 for readability
    freq.resize(highest+1);
    for(auto i : A) 
        freq[i]++;

    std::vector<int> ret;
    auto size = freq.size();
    ret.resize(A.size());

    int place=0;
    for(int idx=1;idx<size;idx++) {
        if(freq[idx]) {
            for(int num=idx+1;num<=highest;num++) 
            {
                if(freq[num]) 
                {
                    while(freq[idx] && freq[num] && idx != num) {
                        ret[place++] = idx;
                        freq[idx]--;
                        ret[place++] = num;
                        freq[num]--;
                    }
                }
            }
        }
    }

    // when we have an uneven number of integers
    // There will be one that will not map, 
    // so add it to the end
    if((size & 2) != 0) {
        for(int idx=1;idx<size;idx++) {
            if(freq[idx]) ret[place++] = idx;
        }
    }

    return ret;
}
static bool assert_true(std::vector<int> a, std::vector<int> b) {
    if(a == b) 
        return true;

    std::cout << "expected : ";
    print(b);
    std::cout << "got      : ";
    print(a);

    return false;
}

#define TEST(A,B) assert(assert_true(solution(A),B))

int main(int argc, char ** argv) 
{
    std::vector<int> ar1;
    std::vector<int> ar2;


    ar1 = {1,2,3,4};
    ar2 = {1,2,3,4};
    TEST(ar1,ar2);

    // Arrangement is such that 
    // 1. gap of zero (3,3)
    // 2. gap of 1 (2,1)
    // 3. gap of 4 (4,6)
    ar1 = {1,1,2,2,3,3,4,6,9};
    ar2 = {1,2,1,2,3,4,3,6,9};
    TEST(ar1,ar2);


    // These will be distributed 
    // 1. (1,2) and (3,4) gap of one
    // 2. (3,6) gap of 3
    // 3. (9,11) gap of 4
    // 4. (9,14) gap of 5 and (14,9)
    ar1 = {1,1,2,2,3,3,4,6,9,9,9,11,14};
    ar2 = {1,2,1,2,3,4,3,6,9,11,9,14,9};
    TEST(ar1,ar2);

    // 1. (1,2) (2,3) (3,4)
    // 2. (6,9)
    // 3. (9,11)
    // 4. (9,14) 
    ar1 = {1,2,2,3,3,4,6,9,9,9,11,14};
    ar2 = {1,2,2,3,3,4,6,9,9,11,9,14};
    TEST(ar1,ar2);


    return 0;
}

