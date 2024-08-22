//https://leetcode.com/problems/encode-and-decode-strings/description/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>

using namespace std;
class Codec {
public:
string intTostr(string str){
        int len = str.length();
        string data_str = "";
        int data_arr[4]={0};
        int i = 3;
        while(len > 0 and i>=0){
            data_arr[i] = len % 10;
            len = len/10;
            --i;
        }
        for(int i = 0; i<4; i++){
            data_str.append(to_string(data_arr[i]));
        }
        return data_str;
    }
    int stringToInt(string str){
        int result = 0;
        for(char ch :str){
            result = result*10 + static_cast<int>(ch - '0');
        }

        return result;
    }
    string encode(vector<string>& strs){
        string res = "";
        for(auto str: strs){
            res.append(intTostr(str));
            res.append(str);
        }
        return res;

    }
    vector<string> decode(string str){
        vector<string> result;
        int i = 0;
        int n = str.length();
        while(i <n){
            int len = stringToInt(str.substr(i,4));
            i +=4;
            result.push_back(str.substr(i,len));
            i +=len;
        }
        return result;
    }
};
