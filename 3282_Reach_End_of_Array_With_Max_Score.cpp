/*
3282. Reach End of Array With Max Score
You are given an integer array nums of length n.
Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
The score for a jump from index i to index j is calculated as (j - i) * nums[i].
Return the maximum possible total score by the time you reach the last index.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int count =0;
        long long temp=nums[0];
        long long sum=0;
        int i=1;
        for(;i<nums.size();i++){
            count++;
            if(nums[i]>temp){
                sum+=count*temp;
                temp=nums[i];
                count = 0;
            }
        }
        sum+=count*temp;
        return sum;
    }
};
int main()
{
    return 0;
}