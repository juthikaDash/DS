//https://leetcode.com/problems/number-of-1-bits/description/
/*******************************************
 * Write a function that takes the binary representation of a positive integer and returns the number of 
set bits
 it has (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 ********************************************/

#include<iostream>
#include <stdio.h>



using namespace std;
class Solution {
    public:
        int hammingWeight(uint32_t n) {
            //first solution
            int count= 0;
           /* while(n){
                count +=n%2;
                n = n>>1;
            }
            */
            //2nd solution
            while(n){
                n = n & (n-1);
                count++;
            }
            return count;
        }
};
int main()
    {
        Solution s ;
        int n;
        cout << "Please enter an integer value: ";
        cin >> n;
        int count = s.hammingWeight(n );
        cout << "Number of 1 Bits:"<< count<<endl;
        return 0;
    }