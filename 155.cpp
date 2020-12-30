//
// Created by zxqnh on 2020/10/25.
//
#include <stack>
#include <climits>

using namespace std;

class MinStack {
private:
    stack<int> xStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int x) {
        xStack.push(x);
        minStack.push(min(minStack.top(), x));
    }

    void pop() {
        xStack.pop();
        minStack.pop();
    }

    int top() {
        return xStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

