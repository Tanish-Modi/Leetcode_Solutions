/*
78. Subsets
Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> ss(vector<int>& nums, vector<vector<int>>& ans,int s) { 
        if(s>=nums.size()){
            return ans;
        }   
        vector<vector<int>>a2;
        a2=ss(nums,ans,s+1);
        a2.push_back({});
        for(int i=0;i<a2.size();i++){
            a2[i].push_back(nums[s]);
            ans.push_back(a2[i]);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans=ss(nums,ans,0);
        ans.push_back({});
        return ans;
    }
};
int main()
{
    return 0;
}