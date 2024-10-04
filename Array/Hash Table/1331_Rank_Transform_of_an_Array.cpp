/*
1331. Rank Transform of an Array
Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:
Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> umap;
        int count = 1;
        for (int i = 0; i < temp.size(); i++) {
            if (umap[temp[i]] == 0) {
                umap[temp[i]] = count++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = umap[arr[i]];
        }
        return arr;
    }
};
int main()
{
    return 0;
}