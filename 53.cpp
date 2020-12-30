//
// Created by zxqnh on 2020/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划
    int maxSubArray(vector<int> &nums) {
        int size = nums.size();
        int pre = nums[0], maxSum = pre;
        for (int i = 1; i < size; i++) {
            pre = max(pre + nums[i], nums[i]);
            maxSum = max(maxSum, pre);
        }
        return maxSum;
    }

    // 利用线段树来做
    struct State {
        int iSum, lSum, rSum, mSum;
    };

    State push(State l, State r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, l.rSum + r.iSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + l.lSum);
        return State{iSum, lSum, rSum, mSum};
    }

    State get(vector<int> &nums, int l, int r) {
        if (l == r)
            return State{nums[l], nums[l], nums[l], nums[l]};
        int m = (l + r) >> 1;
        State lSub = get(nums, l, m);
        State rSub = get(nums, m + 1, r);
        return push(lSub, rSub);
    }

    int maxSubArray1(vector<int> &nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

