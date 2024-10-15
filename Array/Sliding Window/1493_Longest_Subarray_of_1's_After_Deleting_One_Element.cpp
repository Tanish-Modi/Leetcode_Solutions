/*
1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=0;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(flag){
                break;
                }
                flag=true;
            }
            k++;
        }
        int maxm=k;
        for(int i=k;i<nums.size();i++){
            if(nums[i]==0){
                while(nums[i-k]!=0){
                    k--;
                }
                k--;
            }
            k++;
            maxm=max(maxm,k);
        }
        return maxm-1;
    }
};

int main()
{
    return 0;
}