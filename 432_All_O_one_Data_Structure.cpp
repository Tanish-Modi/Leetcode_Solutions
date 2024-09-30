/*
432. All O`one Data Structure
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:
AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;

class AllOne {
    unordered_map<string,int> freq;
    set<pair<int,string>> s;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int n=freq[key]++;
        s.erase({n,key});
        s.insert({n+1,key});
    }
    
    void dec(string key) {
        int n=freq[key]--;
        s.erase({n,key});
        if(--n>0){
        s.insert({n,key});
        }
    }
    
    string getMaxKey() {
        if(s.empty()){
            return "";
        }
        return s.rbegin()->second;
    }
    
    string getMinKey() {
        if(s.empty()){
            return "";
        }
        return s.begin()->second;
    }
};

int main()
{

//Your AllOne object will be instantiated and called as such:
AllOne* obj = new AllOne();
string key ="keys";
obj->inc(key);
obj->dec(key);
string param_3 = obj->getMaxKey();
string param_4 = obj->getMinKey();

    return 0;
}