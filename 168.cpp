//
// Created by zxqnh on 2020/11/7.
//
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        stack<int> remainder;
        while (n != 0) {
            n--;
            remainder.push(n % 26);
            n /= 26;
        }
        stringstream ss;
        while (!remainder.empty()) {
            ss << char(remainder.top() + 'A');
            remainder.pop();
        }
        return ss.str();
    }
};

