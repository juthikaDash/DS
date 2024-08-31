//https://leetcode.com/problems/decode-ways/description/

    /*
    Dynamic Programming
    https://www.youtube.com/watch?v=o1i7JYWbwOE
    1 4 2 2 
    1, 4, 2, 2
    14, 2, 2
    14, 22
    1, 4, 22 
 
    So there are 4ways
    lets try to see if there is 3 after 2
     then there are 2 posibilities either it will be treated as single digit or duuble digit.
     Note: if it is 0 then it can not use alone and it should be use as doble number which is <= 26
     N0te: the string can not start with 0

*/  
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
        int numDecodings(string s) {
        //length 0
        //The string can not start with 0
        if(s.length() == 0 || s[0] == '0'){
            return 0;
        }
        //if the string is 1 digit then it can be between 1-9
        if(s.length() == 1){
            return 1;
        }
        // We need to previous 2 digits only as if the new number is treated with as single digit then it will be part of same number
       // if we can make it as a double digit then it can also be part of the option from current - 2 position
        int count1 = 1;
        int count2 = 1;

        for(int i=1;i<s.length(); i++){
            //we have to decide the new digit as signle number
            int d = s[i] - '0';
            //when we chose the new digit as double digit bumber by atatching to the previous
            int dd = (s[i-1] - '0')*10 + d;

            int count = 0;
            if(d > 0){
                count += count2;
            }

            if(dd >=10 && dd <=26){
                count += count1;
            }

            count1 = count2;
            count2 = count;   
        }
        return count2;   
    }
};
