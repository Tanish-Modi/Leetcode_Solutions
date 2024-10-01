/*
1310. XOR Queries of a Subarray
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
Return an array answer where answer[i] is the answer to the ith query.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> dp(arr.size()+1);
        dp[0]=0;
        for(int i=0;i<arr.size();i++){
            dp[i+1]=dp[i]^arr[i];
        }
        for(int i=0;i<queries.size();i++){
            ans.push_back(dp[queries[i][0]]^dp[queries[i][1]+1]);
        }
        return ans;
    }
};
int main()
{
    return 0;
}