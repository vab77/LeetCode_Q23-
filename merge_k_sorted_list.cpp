/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/
#include<bits/stdc++.h>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Create a Min Heap(priority_queue) 
        priority_queue<int,vector<int>,greater<int>> pq;

        //Insert the values in pq;
        int n = lists.size();
        for(int i = 0 ; i < n ; i++){
            while(lists[i] != NULL){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }        

        //Make a new LL for storing the merged lists

        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;//points to the head of the new list 
        while(!pq.empty()){
            ans->next = new ListNode(pq.top());
            pq.pop();
            ans=ans->next;
        }
        return dummy->next;

    }
};