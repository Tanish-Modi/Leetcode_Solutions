/*
2641. Cousins in Binary Tree II
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.
Two nodes of a binary tree are cousins if they have the same depth with different parents.
Return the root of the modified tree.
Note that the depth of a node is the number of edges in the path from the root node to it.
*/
#include<bits/stdc++.h>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        root->val=0;
        while(!bfs.empty()){
            int sum=0;
            queue<int>s;
            int size=bfs.size();
            TreeNode* temp=NULL;
            for(int i=0;i<size;i++){
                temp=bfs.front()->left;
                if(temp==NULL){
                    s.push(0);
                }else{
                    s.push(temp->val);
                }
                    bfs.push(temp);
                temp=bfs.front()->right;
                if(temp==NULL){
                    s.push(0);
                }else{
                    s.push(temp->val);
                }
                    bfs.push(temp);
                bfs.pop();
            }
            int sum2=0;
            for(int i=0;i<2*size;i++){
                sum2+=s.front();
                if(i%2!=0){
                    s.push(sum2);
                    sum+=sum2;
                    sum2=0;
                }
                s.pop();
            }
            for(int i=0;i<2*size;i++){
                temp=bfs.front();
                if(temp!=NULL){
                temp->val=sum-s.front();
                bfs.push(temp);
                }
                if(i%2!=0){
                    s.pop();
                }
                bfs.pop();
            }
        }
        return root;
    }
};
int main()
{
    return 0;
}