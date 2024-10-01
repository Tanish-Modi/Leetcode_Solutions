/*
3217. Delete Nodes From Linked List Present in Array
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
*/
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution
 {
 public:
     bool search(vector<int> &arr, int low, int high, int x)
     {
         if (high >= low)
         {
             int mid = low + (high - low) / 2;
             if (arr[mid] == x)
                 return true;
             if (arr[mid] > x)
                 return search(arr, low, mid - 1, x);
             return search(arr, mid + 1, high, x);
         }
         return false;
     }
     ListNode *modifiedList(vector<int> &nums, ListNode *head)
     {
         ListNode *ptr = head;
         ListNode *ptr2 = ptr;
         sort(nums.begin(), nums.end());
         while (ptr != NULL)
         {
             if (search(nums, 0, nums.size() - 1, ptr->val))
             {
                 if (ptr == head)
                 {
                     head = head->next;
                 }
                 else
                 {
                     ptr2->next = ptr->next;
                     ptr = ptr->next;
                     continue;
                 }
             }
             ptr2 = ptr;
             ptr = ptr->next;
         }
         return head;
     }
 };
 int main()
 {
     return 0;
 }