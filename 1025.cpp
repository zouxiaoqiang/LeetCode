//
// Created by zxqnh on 2020/11/18.
//
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        dp[1] = false;
        for (int i = 2; i <= N; i++) {
            int n = sqrt(i), j = 1;
            for (; j <= n; j++) {
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};

