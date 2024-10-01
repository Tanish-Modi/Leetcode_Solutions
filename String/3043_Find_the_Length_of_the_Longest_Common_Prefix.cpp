/*
3043. Find the Length of the Longest Common Prefix

You are given two arrays with positive integers arr1 and arr2.
A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.
You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int len(string s1,string s2){
        int i=0;
        for(;i<s1.size()&&s2.size();i++){
            if(s1[i]!=s2[i]){
                break;
            }
        }
        return i;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> s1;
        vector<string> s2;
        for(auto i:arr1){
            s1.push_back(to_string(i));
        }
        for(auto i:arr2){
            s2.push_back(to_string(i));
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int i=0,j=0,maxlen=0;
        while(i<s1.size()&&j<s2.size()){
            maxlen=max(maxlen,len(s1[i],s2[j]));
            if(s1[i]>s2[j]){
                j++;
            }else{
                i++;
            }
        }
        return maxlen;
    }
};
int main()
{
    return 0;
}