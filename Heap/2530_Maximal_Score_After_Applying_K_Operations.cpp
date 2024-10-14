/*
2530. Maximal Score After Applying K Operations
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:
choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k--){
            int temp=pq.top();
            pq.pop();
            score+=temp;
            pq.push((temp+2)/3);
        }
        return score;
    }
};
int main()
{
    return 0;
}