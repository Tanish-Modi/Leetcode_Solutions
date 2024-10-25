/*
1233. Remove Sub-Folders from the Filesystem
Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,bool>folders;
        vector<string>ans;
        sort(folder.begin(),folder.end());
        for(int i=0;i<folder.size();i++){
            string s="";
            for(char c:folder[i]){
                if(c=='/'){
                    if(folders.find(s)!=folders.end()){
                        break;
                    }
                }
                s+=c;
            }
            if(s.size()==folder[i].size()){
                folders[s]=0;
                ans.push_back(s);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}