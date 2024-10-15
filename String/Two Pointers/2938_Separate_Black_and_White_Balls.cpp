/*
2938. Separate Black and White Balls
There are n balls on a table, each ball has a color black or white.
You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.
In each step, you can choose two adjacent balls and swap them.
Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Two Pointer
class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size()-1;
        long long sum=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                sum+=n-i;
                n--;
            }
        }
        return sum;
    }
};

// // Greedy
// class Solution {
// public:
//     long long minimumSteps(string s) {
//         int n=0;
//         long long sum=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='1'){
//                 n++;
//             }else{
//                 sum+=n;
//             }
//         }
//         return sum;
//     }
// };

int main()
{
    return 0;
}