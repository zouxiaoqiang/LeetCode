//
// Created by zxqnh on 2020/10/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int left = 0, right = 1;
        int profit = 0, priceSize=  prices.size();
        while (right < priceSize) {
            if (prices[right] <= prices[left])
                left = right;
            else if (profit < prices[right] - prices[left])
                profit = prices[right] - prices[left];
            right++;
        }
        return profit;
    }

    int maxProfit1(vector<int> &prices) {
        int minPrice = 1e9, maxProfit = 0;
        for (int price: prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return maxProfit;
    }

    int maxProfit2(int* prices, int pricesSize){
        int left = 0, right = 1;
        int profit = 0;
        while (right < pricesSize) {
            if (prices[right] <= prices[left])
                left = right;
            else if (profit < prices[right] - prices[left])
                profit = prices[right] - prices[left];
            right++;
        }
        return profit;
    }
};

int main() {
    Solution s = Solution();
    vector<int> prices({7, 1, 5, 3, 6, 4});
    s.maxProfit(prices);
    return 0;
}
