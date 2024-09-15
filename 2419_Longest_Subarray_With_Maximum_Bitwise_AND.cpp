/*
2419. Longest Subarray With Maximum Bitwise AND
You are given an integer array nums of size n.
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.
The bitwise AND of an array is the bitwise AND of all the numbers in it.
A subarray is a contiguous sequence of elements within an array.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxm=nums[0];
        for(int i=1;i<nums.size();i++){
            maxm=max(maxm,nums[i]);
        }
        int k=0;
        for(int i=0;i<nums.size();i++){
            int x=0;
            for(;i<nums.size()&&nums[i]==maxm;i++){
                x++;
            }
            k=max(k,x);
        }
        return k;
    }
};
int main()
{
    return 0;
}