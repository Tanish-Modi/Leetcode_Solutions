/*
You are given two integers m and n, which represent the dimensions of a matrix.
You are also given the head of a linked list of integers.
Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
Return the generated matrix.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int r = 0;
        int i = r;
        int j = r;
        while (head != NULL) {
            while (head != NULL && j < n - r) {
                ans[i][j] = head->val;
                head = head->next;
                j++;
            }
            j--;
            i++;
            while (head != NULL && i < m - r) {
                ans[i][j] = head->val;
                head = head->next;
                i++;
            }
            i--;
            j--;
            while (head != NULL && j >= r) {
                ans[i][j] = head->val;
                head = head->next;
                j--;
            }
            j++;
            i--;
            while (head != NULL && i > r) {
                ans[i][j] = head->val;
                head = head->next;
                i--;
            }
            i++;
            j++;
            r++;
        }
        return ans;
    }
};
int main()
{
    return 0;
}