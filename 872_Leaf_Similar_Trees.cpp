/*
872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
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
    void check(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        if(root->right==NULL&&root->left==NULL){
            v.push_back(root->val);
            return;
        }
        check(root->left,v);
        check(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        check(root1,a);
        check(root2,b);
        if(a.size()!=b.size()){
            return 0;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }
};
int main()
{
    return 0;
}