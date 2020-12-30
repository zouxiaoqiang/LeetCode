//
// Created by zxqnh on 2020/10/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (nums[left] + nums[right] < target)
                left++;
            while (nums[left] + nums[right] > target)
                right--;
            if (nums[left] + nums[right] == target)
                break;
        }
        return vector<int>({left + 1, right + 1});
    }
};

