//
// Created by zxqnh on 2020/10/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int priceSize = prices.size(), sum = 0, profit = 0;
        int left = 0, right = 1;
        while (right < priceSize) {
            if (prices[right] <= prices[right - 1]) {
                left = right;
                sum += profit;
                profit = 0;
            } else if (profit < prices[right] - prices[left])
                profit = prices[right] - prices[left];
            right++;
        }
        sum += profit;
        return sum;
    }
};
