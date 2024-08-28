//https://leetcode.com/problems/merge-k-sorted-lists/description/
//https://leetcode.com/problems/merge-k-sorted-lists/description/
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeList = new ListNode(0);
        ListNode* prev = mergeList;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                prev->next = list1;
                list1 = list1->next;
            }
            else{
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        if(list1 != NULL){
            prev->next = list1;
        }

        if(list2 != NULL){
            prev->next = list2;
        }

        return mergeList->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){ return NULL;}
        int list_count = lists.size();
        int interval = 1;
        while(interval < list_count){
            for(int i = 0; i< list_count - interval; i += interval*2 ){
                lists[i] =  mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};