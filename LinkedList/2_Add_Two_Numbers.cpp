//https://leetcode.com/problems/add-two-numbers/description/
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* l3;
        ListNode** node = &l3;

        while(l1 != nullptr || l2 != nullptr || sum > 0){
            if(l1 != nullptr){
                sum +=l1->val;
                l1 = l1->next;
            }
            if(l2!= nullptr){
                sum +=l2->val;
                l2 = l2->next;
            }

            *(node) = new ListNode(sum%10);
            sum = sum/10;
            node = &((*node)->next) ;
        }

        return l3;
    }    
};

