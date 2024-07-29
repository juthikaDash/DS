//https://leetcode.com/problems/sum-of-two-integers/description/
/****************************************************************
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*****************************************************************/
#include<iostream>


using namespace std;

class Solution {
    public:

    int getSum(int a,int b ){
        while(b!= 0){ 
            uint32_t  carry =  a & b;
            a = a ^ b;
            b =carry << 1;
        }
        return a;
    }
    
};
int main()
    {
        Solution s ;
        int sum = s.getSum(4 , 5);
        cout << "Sum:"<< sum<<endl;
        return 0;
    }