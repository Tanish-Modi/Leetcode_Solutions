/*
884. Uncommon Words from Two Sentences
A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> freq;
        istringstream ss1(s1);
        istringstream ss2(s2);
        string s;
        while(ss1>>s){
            freq[s]++;
        }
        while(ss2>>s){
            freq[s]++;
        }
        vector<string> ans;
        for(auto i:freq){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}