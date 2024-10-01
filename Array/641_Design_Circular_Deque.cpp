/*
641. Design Circular Deque

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:
MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class MyCircularDeque {
    vector<int> m;
    int first = -1, size = 0;

public:
    MyCircularDeque(int k) { m.resize(k); }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (size == 0) {
            first = 0;
        } else {
            first += m.size() - 1;
            first %= m.size();
        }
        size++;
        m[first] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (size == 0) {
            first = 0;
        }
        size++;
        m[(first + size - 1) % m.size()] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (size == 0) {
            first = -1;
        } else {
            first++;
            first %= m.size();
            size--;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (size == 0) {
            first = -1;
        }else{
            size--;
        }
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return m[first];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return m[(first + size - 1) % m.size()];
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (size == m.size()) {
            return true;
        }
        return false;
    }
};

int main()
{
//Your MyCircularDeque object will be instantiated and called as such:
int k=3;
int value=5;
MyCircularDeque* obj = new MyCircularDeque(k);
value=10;
bool param_1 = obj->insertFront(value);
bool param_2 = obj->insertLast(value);
bool param_3 = obj->deleteFront();
bool param_4 = obj->deleteLast();
int param_6 = obj->getRear();
int param_5 = obj->getFront();
bool param_7 = obj->isEmpty();
bool param_8 = obj->isFull();
cout<<param_1<<','<<param_2<<','<<param_3<<','<<param_4<<','<<param_5<<','<<param_6<<','<<param_7<<','<<param_8;
    return 0;
}