//https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10
/**
 * Definition for singly-linked list.
 */
#include<iostream>
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr){
            ListNode* Next = curr->next;
            if(!Next){ return head;}

            //Create a new node
            ListNode* node = new ListNode(gcd(curr->val,Next->val));
            curr->next = node;
            node->next = Next;
            curr = curr->next->next;
        }
        return head;
    }

    int gcd(int a, int b){
       while(b>0){
        int copyA = a;
        a = b;
        b = copyA%b;

       }
       return a;
    }
};
