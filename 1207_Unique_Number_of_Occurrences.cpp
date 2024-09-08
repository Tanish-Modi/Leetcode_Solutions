/*
1207. Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
*/
#include<iostream>
#include<vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> setoffreq;
        for(auto i:freq){
            if(setoffreq.find(i.second)!=setoffreq.end()){
                return false;
            }
            setoffreq.insert(i.second);
        }
        return true;
    }
};
int main()
{
    return 0;
}