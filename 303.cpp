//
// Created by zxqnh on 2020/11/17.
//
#include <vector>

using namespace std;


class NumArray {
private:
    int *sum;
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        sum = new int[size + 1];
        for (int i = 0; i < size; i++)
            sum[i + 1] = sum[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

