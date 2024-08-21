//https://leetcode.com/problems/group-anagrams/description/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string get_str_val(string str){
        int string_map[26] = {0};
        for(int i = 0; i<str.length(); i++){
            string_map[str[i] - 'a'] +=1;
        }
        string return_val ="";
        for(int num:string_map){
            return_val.append(to_string(num));
            return_val.append("#");
        }

        return return_val;
    }
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string> > mapper;
      vector<vector<string> > res;

      for(auto str:strs){
        auto str_val = get_str_val(str);
        mapper[str_val].push_back(str);
      }  

      auto it =  mapper.begin();
      while (it != mapper.end())
      {
        res.push_back(it->second);
        it++;
      }
      
      return res;
    }
};



