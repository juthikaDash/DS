//https://leetcode.com/problems/string-to-integer-atoi/description/
#include<iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int i = 0;

        //skipping the wite space
        while(s[i] == ' '){i++;}

        //Negative sige check
        if(s[i] == '-'){ sign = -1; i++;}
        else if(s[i] == '+'){i++;}

        for(; i < s.length();i++ ){
            // If don't find a digit any more then return the num till now
            if(!isdigit(s[i])){
                return num;
            }
            int digit = (s[i] - '0')*sign;
            cout<<"digit:"<<digit<<endl;
            if(num > INT_MAX/10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)){
                return INT_MAX;
            }

            if(num < INT_MIN/10 || (num == INT_MIN / 10 && digit < INT_MIN % 10)){
                return INT_MIN;
            }

            num = num *10 + digit;
            cout<<"num:"<<num<<endl;

        }

        return (num);
    }
};
