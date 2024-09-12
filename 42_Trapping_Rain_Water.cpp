/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft=0,maxright=height.size()-1,sum=0;
        for(int i=0;i<height.size();i++){
            if(height[maxleft]<height[i]){
                maxleft=i;
                continue;
            }
            maxright=i;
            for(int j=i;j<height.size();j++){
                if(height[maxleft]<=height[j]){
                    maxright=j;
                    break;
                }
                maxright=(height[maxright]>height[j])?maxright:j;
            }
            sum+=max(min(height[maxleft],height[maxright])-height[i],0);
        }
        return sum;
    }
};
int main()
{
    return 0;
}