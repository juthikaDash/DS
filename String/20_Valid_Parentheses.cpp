//https://leetcode.com/problems/valid-parentheses/description/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    bool validate_entry(stack<char>& my_stack, char ch){
        if(!my_stack.empty() and my_stack.top() == ch){
            my_stack.pop();
            return true;
        }
        else
            return false;
    }
    bool isValid(string s) {
        //if string is empty
        if(!s.size()){ return true;}
        //creating a stack
        stack<char> my_stack;
        for(auto c:s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    my_stack.push(c);
                    continue;
                case ')':
                    if(!validate_entry(my_stack,'(')){
                        return false;
                    }
                    break;
                case '}':
                    if(!validate_entry(my_stack,'{')){
                        return false;
                    }
                    break;
                case ']':
                    if(!validate_entry(my_stack,'[')){
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        if(!my_stack.empty()){ return false;}

        return true;
    }
};
