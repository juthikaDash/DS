#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int count = 0;
        //removing extra closing braces
        for(auto c: s){
            //if c is ( then increment the counter and append to res
            if(c == '('){
                count++;
                res += c;
                //res.append(c);
            }
            //if c ) and count is >0 then decrement the count and append to res
            else if(c == ')' and count > 0){
                count--;
                res += c;
                //res.app(c);
            }
            //if c is a char then just append i.e not a )  
            else if( c != ')'){
                res += c;
                //res.append(c);
            }
        }

        //removing extra opening braces
        string result;
        for(int i =res.size()-1 ; i>=0;i--){
            char c = res[i];
            if(c == '(' and count >0){
                count--;
            }
            else{
                result = c + result;
            }
        }

        return result;
    }
};
int main(){
   Solution s;
   string str = s.minRemoveToMakeValid("lee(t(c)o)de)");
   cout <<"Result : "<< str<<endl;
      return 0;
}