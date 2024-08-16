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
    void reorderList(ListNode* head) {
        if(head == nullptr){ return;}
        //slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        //go to the middle
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }

        //reverse the send half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* temp;
        //reverse the list
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // now merge 2 linked list
        ListNode* first = head;
        ListNode* second = prev;

        while(second->next != nullptr){
            temp = first->next;
            first->next = second;
            first = temp;
            temp = second->next;
            second->next = first;
            second = temp;

        }
    }
};