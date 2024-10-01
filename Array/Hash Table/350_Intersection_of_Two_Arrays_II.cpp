/*
350. Intersection of Two Arrays II
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        unordered_map<int,int>freq;
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(freq.find(nums2[i])!=freq.end()&&freq[nums2[i]]!=0){
                nums.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }
        return nums;
    }
};
int main()
{
    return 0;
}