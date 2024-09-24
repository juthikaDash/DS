//https://leetcode.com/problems/palindrome-number/description/
// Planning:
// - Using mathematic fundamental lets firt recreate it's opp number
// - we can return flase safely for negative number from the description
// - We can find the last digit by modulus operator (num %10)
// - Then we can reduce the number by (num /10)
// - For the new number firt multiply base (10 here) to the previous number then add the last digit
// - Before do the above step we should verify that if we add this it shouldn't overflow the range.
// - Once the number is constrcted the verify and return the result.
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int num = x, newNum = 0, rem =0;
        if(num<0){ return false;}

        while(num != 0){
            rem = num %10;
            num = num/10;

            //check if adding to new num will cross the integer boundary
            if(newNum > INT_MAX/10 || newNum < INT_MIN/10 ){
                return false;
            }

            newNum = (newNum*10)+ rem;
        }

        if(newNum != x){ return false;}
        return true;
    }
};
