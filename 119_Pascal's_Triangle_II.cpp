/*
119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> mainrow;
        mainrow.push_back(1);
        if(rowIndex==0){
            return mainrow;
        }
        mainrow.push_back(1);
        for(int i=1;i<rowIndex;i++){
            vector<int>r2;
            r2.push_back(1);
            for(int j=0;j<mainrow.size()-1;j++){
            r2.push_back(mainrow[j]+mainrow[j+1]);
            }
            r2.push_back(1);
            mainrow=r2;
        }
        return mainrow;
    }
};
int main()
{
    return 0;
}