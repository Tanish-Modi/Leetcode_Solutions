/*
450. Delete Node in a BST
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* get_pre(TreeNode* root){
        root=root->left;
        if(root==NULL){
            return NULL;
        }
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL&&root->right==NULL&&root->val==key){
            delete(root);
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }else{
            TreeNode* ipre=get_pre(root);
            if(ipre==NULL){
                root=root->right;
            }else{
            root->val=ipre->val;
            root->left=deleteNode(root->left,ipre->val);
            }
        }
        return root;
    }
};
int main()
{
    return 0;
}