//
// Created by zxqnh on 2020/10/5.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p, q = 0, r = 1;
        for (int i = 1; i <= n; i++) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}

