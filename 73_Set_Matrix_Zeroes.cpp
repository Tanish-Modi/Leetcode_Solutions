/*
73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r;
        vector<int> c;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(!matrix[i][j]){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(auto i:r){
            for(int j=0;j<matrix[i].size();j++){
                matrix[i][j]=0;
            }
        }
        for(auto j:c){
            for(int i=0;i<matrix.size();i++){
                matrix[i][j]=0;
            }
        }
    }
};
int main()
{
    return 0;
}