/*
2583. Kth Largest Sum in a Binary Tree
You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
    vector<long long> ans;

public:
    // void solve(queue<TreeNode*>&v){
    //     if(v.empty()){
    //         return;
    //     }
    //     long long sum=0;
    //     for(int i=v.size()-1;i>=0;i--){
    //         sum+=v.front()->val;
    //         TreeNode* temp=v.front()->left;
    //         if(temp!=NULL)
    //         v.push(temp);
    //         temp=v.front()->right;
    //         if(temp!=NULL)
    //         v.push(temp);
    //         v.pop();
    //     }
    //     ans.push_back(sum);
    //     solve(v);
    // }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> v;
        v.push(root);
        while (!v.empty()) {
            long long sum = 0;
            for (int i = v.size() - 1; i >= 0; i--) {
                sum += v.front()->val;
                TreeNode* temp = v.front()->left;
                if (temp != NULL)
                    v.push(temp);
                temp = v.front()->right;
                if (temp != NULL)
                    v.push(temp);
                v.pop();
            }
            ans.push_back(sum);
        }
        if (ans.size() < k) {
            return -1;
        }
        sort(ans.rbegin(), ans.rend());
        return ans[k - 1];
    }
};
int main()
{
    return 0;
}