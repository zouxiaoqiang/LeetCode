//
// Created by zxqnh on 2020/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    // dp[i]表示选择走第i个位置的最小代价
    int minCostClimbingStairs(vector<int> &cost) {
        int size = cost.size();
        int dp[size];
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < size; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[size - 1], dp[size - 2]);
    }

    // 使用滚动数组
    int minCostClimbingStairs1(vector<int> &cost) {
        int size = cost.size();
        int first = cost[0], second = cost[1];
        int tmp;
        for (int i = 2; i < size; i++) {
            tmp = second;
            second = cost[i] + min(first, second);
            first = tmp;
        }
        return min(first, second);
    }
};
