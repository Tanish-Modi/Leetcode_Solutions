/*
1497. Check If Array Pairs Are Divisible by k
Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return true If you can find a way to do that or false otherwise.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[(arr[i]%k+k)%k]++;
        }
        for(auto i:freq){
            if((i.first ==0||(k-i.first)==i.first)){
                if(i.second%2!=0)
                return false;
            }else if(i.second!=freq[k-i.first]){
                return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}