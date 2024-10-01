/*
1684. Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> all(26,false);
        for(auto s:allowed){
            all[s-'a']=true;
        }
        int count=words.size();
        for(auto w:words){
            for(auto c:w){
                if(all[c-'a']!=true){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}