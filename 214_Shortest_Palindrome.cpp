/*
214. Shortest Palindrome
You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string str = "";
        int len = 1, i = 0;
        bool flag=false;
        for (int j = s.size() - 1; j > 0; j--) {
            int k = j;
            if(flag){
                break;
            }
            if (s[i] == s[j]) {
                while (j > i && s[i] == s[j]) {
                    i++;
                    j--;
                    if (i >= j) {
                        if (k + 1 > len) {
                            len = k + 1;
                        }
                        flag=true;
                        break;
                    }
                }
                j = k;
                i = 0;
            }
        }
        for (int j = s.length() - 1; j >= len; j--) {
            str += s[j];
        }
        return str + s;
    }
};

int main()
{
    return 0;
}