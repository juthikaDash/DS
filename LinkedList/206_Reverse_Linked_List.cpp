//https://leetcode.com/problems/reverse-linked-list/description/
/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?


*/



 // Definition for singly-linked list.

 
#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //Approch 1: Iterative
    ListNode* reverseList(ListNode* head) {
       ListNode* prev = nullptr;
       ListNode* curr = head;
       ListNode* ahead = nullptr;

       while(curr != nullptr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
       } 
       return prev;
    }
    /* Approch 2 : recursive 
    Follow the steps below to solve the problem:
    - Divide the list in two parts – first node and rest of the linked list.
    - Call reverse for the rest of the linked list.
    - Link the rest linked list to first.
    - Fix head pointer to NULL.
    */
    ListNode* reverseList_recur(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        // reverse the rest of linked list and put the first element at the end 
        ListNode* rest = reverseList_recur(head->next);

        // Make the current head as last node of remaining linked list
        head->next->next = head;

        //update the curreent head to null
        head->next = NULL;

        return rest;
    }
};