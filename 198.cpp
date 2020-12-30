//
// Created by zxqnh on 2020/11/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]);
        int tmp;
        for (int i = 2; i < size; i++) {
            tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
};

