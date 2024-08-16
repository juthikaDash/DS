//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 


*/
#include<iostream>
using namespace std;
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode* N = head;
        for(int i = 0; i< n;i++){
            N = N->next;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(N!= nullptr){
            N = N->next;
            prev = curr;
            curr = curr->next;
        }
        if(prev == nullptr){
            return head->next;
        }

        //remove nth node
        prev->next = curr->next;
        curr->next = nullptr;
        //return head;
        return head;
    }
};