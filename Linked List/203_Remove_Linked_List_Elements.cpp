/*
203. Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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
    ListNode* removeElements(ListNode* head, int val) {
    ListNode* ptr=head;
    while(ptr!=NULL&&ptr->next!=NULL){
        if(ptr->next->val==val){
            ListNode*x=ptr->next;
            ptr->next=ptr->next->next;
            delete(x);
        }else{
        ptr=ptr->next;
        }
    }   
    if(head!=NULL&&head->val==val){
        ListNode*x=head;
        head=head->next;
        delete(x);
    }
    return head;
    }
};
int main()
{
    return 0;
}