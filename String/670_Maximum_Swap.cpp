//https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17
//Like selection sort
//Time Complexicity O(n2)
//Space complexity O(n)

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        if(num <10){ return num;}

        string digit = to_string(num);
        int n  = digit.size();

        for(int i = 0; i<n-1;i++){
            int maxDigitIdx = i;
            for(int j = i+1; j <n; j++){
                if(digit[maxDigitIdx] <= digit[j]){
                    maxDigitIdx = j;
                }
            }

            if(maxDigitIdx != i and digit[maxDigitIdx] != digit[i]){
                swap(digit[maxDigitIdx], digit[i]);
                break;
            }
        }
        return stoi(digit);
    }

};