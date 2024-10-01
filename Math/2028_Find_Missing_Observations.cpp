/*
2028. Find Missing Observations

You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.
The average value of a set of k numbers is the sum of the numbers divided by k.
Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        double sum=0;
        int m=rolls.size();
        for(int i=0;i<m;i++){
            sum+=rolls[i];
        }
        int netsum=mean*(n+m)-sum;
        //sum of n numbers must be netsum
        sum=double(netsum)/n;
        if(sum>6||sum<1){
            return {};
        }
        int rem=netsum%n;
        vector<int> ans(n,int(sum));
        int i=0;
        while(rem>0){
            if(rem>6-ans[i]){
                rem-=6-ans[i];
                ans[i]=6;
            }else{
                ans[i]+=rem;
                break;
            }
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution case1;
    vector<int> rolls = {3,2,4,3};
    int mean = 4, n = 2;
    vector<int> ans=case1.missingRolls(rolls, mean, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}