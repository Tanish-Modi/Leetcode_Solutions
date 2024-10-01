/*
725. Split Linked List in Parts
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts.
*/
#include<iostream>
#include<vector>
#include<string>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode *ptr = head, *ptr2 = head;
        int count = 0;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        int num = count / k;
        count %= k;
        ptr = head;
        for (int i = 0; i < k; i++) {
            ans.push_back(ptr);
            for (int j = 0; j < num; j++) {
                ptr2 = ptr;
                ptr = ptr->next;
            }
            if (count != 0 && ptr != NULL) {
                ptr2 = ptr;
                ptr = ptr->next;
                count--;
            }
            if (ptr2 != NULL)
                ptr2->next = NULL;
        }
        return ans;
    }
};
int main()
{
    return 0;
}