/*
1381. Design a Stack With Increment Operation
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:
CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class CustomStack {
    int i=0;
    vector<int>st;
public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
    }
    
    void push(int x) {
        if(i<st.size()){
            st[i++]=x;
        }
    }
    
    int pop() {
        if(i<=0){
            return -1;
        }
        return st[--i];
    }
    
    void increment(int k, int val) {
        for(int j=0;j<i&&j<k;j++){
            st[j]+=val;
        }
    }
};

int main()
{
//Your CustomStack object will be instantiated and called as such:
int maxSize=5;
CustomStack* obj = new CustomStack(maxSize);
obj->push(10);
int param_2 = obj->pop();
obj->increment(2,40);
    return 0;
}