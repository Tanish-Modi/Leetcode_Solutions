/*
1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int i=0,j=0;
        while(k!=0&&i<nums.size()){
            if(nums[i]==0){
                k--;
            }
            count++;
            i++;
        }
        int maxm=count;
        for(;i<nums.size();i++){
            if(nums[i]==0){
                while(nums[j]!=0){
                    j++;
                    count--;
                }
                j++;
                continue;
            }else{
                count++;
            }
            maxm=max(maxm,count);
        }
        return maxm;
    }
};
int main()
{
    Solution case1;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<case1.longestOnes(nums,k);
    return 0;
}