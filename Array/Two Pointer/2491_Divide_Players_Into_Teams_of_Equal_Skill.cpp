/*
2491. Divide Players Into Teams of Equal Skill
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
The chemistry of a team is equal to the product of the skills of the players on that team.
Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int x=skill[0]+skill[skill.size()-1];
        long long sum=0;
        int j=skill.size()-1,i=0;
        while(i<j){
            if(skill[i]+skill[j]!=x){
                return -1;
            }
            sum+=skill[i]*skill[j];
            i++;j--;
        }
        return sum;
    }
};
int main()
{
    return 0;
}