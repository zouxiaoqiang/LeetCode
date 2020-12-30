//
// Created by zxqnh on 2020/10/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (auto num: nums)
            ans ^= num;
        return ans;
    }
};

