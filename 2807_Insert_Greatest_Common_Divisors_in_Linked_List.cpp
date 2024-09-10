/*
2807. Insert Greatest Common Divisors in Linked List
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*ptr1=head;
        ListNode*ptr2=head->next;
        while(ptr2!=NULL){
            int temp=__gcd(ptr1->val,ptr2->val);
            ListNode *x=new ListNode(temp);
            x->next=ptr2;
            ptr1->next=x;
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        return head;
    }
};
int main()
{
    return 0;
}