//https://leetcode.com/problems/reverse-integer/description/
#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        int pop = 0;
        while(x !=0){
            pop =x%10;
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10){
                return 0;
            }
            reverse = (reverse *10) + pop;
            x =x/10;
        }

        return reverse;
        
    }
};
