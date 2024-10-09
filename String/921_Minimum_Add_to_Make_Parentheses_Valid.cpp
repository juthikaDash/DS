//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrakets = 0, closeBrakets = 0;

        for(char c: s){
            if(c == '('){
                openBrakets++;
            }
            else{
                if(openBrakets>0)
                    openBrakets--;
                else
                    closeBrakets++;
            }
        }
        return closeBrakets + openBrakets;
    }
};

int main(){
    Solution s;
    string input = "(((";
    int output = s.minAddToMakeValid(input);
    cout<< "Minimum Add to Make Parentheses Valid : "<<output<<endl;


    return 0;
}