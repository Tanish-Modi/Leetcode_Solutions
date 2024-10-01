/*
386. Lexicographical Numbers
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.push_back(1);
        int num = 1;
        while(ans.size() < n){
            if(num * 10 <= n){
                num *= 10;
            } else {
                while(num % 10 == 9 || num + 1 > n){
                    num /= 10;
                }
                num++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};

int main()
{
    return 0;
}