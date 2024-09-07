/*
238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0]=1;
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i-1] * nums[i - 1];
        }
        int m=1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            m *= nums[i+1];
            ans[i]=ans[i]*m;
        }
        return ans;
    }
};
int main()
{
    return 0;
}