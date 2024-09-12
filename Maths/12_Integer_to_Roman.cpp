//https://leetcode.com/problems/integer-to-roman/description/

#include<iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string roman;
        int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int count = 12;
        while(num){
         int div = num/number[count];
         num = num % number[count];

         while(div--){
            roman.append(sym[count]);

         }
         count--;
        }
        return roman;
    }
};
