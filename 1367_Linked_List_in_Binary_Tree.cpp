/*
1367. Linked List in Binary Tree
Given a binary tree root and a linked list with head as the first node. 
Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards.
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


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->val == head->val) {
            return solve(head->next, root->left) ||
                   solve(head->next, root->right);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL)
            return false;

        if (solve(head, root))
            return true;

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
int main()
{
    return 0;
}