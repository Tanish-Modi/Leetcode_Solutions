/*
670. Maximum Swap
You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int j = 0; j < s.size(); j++) {
            int i = j;
            int k = i;
            char c = '0';
            for (; i < s.size(); i++) {
                if (c - '0' <= s[i] - '0') {
                    k = i;
                    c = s[i];
                }
            }
            if (s[k] != s[j]) {
                s[k] = s[j];
                s[j] = c;
                break;
            }
        }
        return stoi(s);
    }
};
int main()
{
    return 0;
}