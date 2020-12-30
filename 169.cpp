//
// Created by zxqnh on 2020/11/8.
//
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0], cnt= 1, size = nums.size();
        int i = 1;
        while (i < size) {
            if (num == nums[i]) cnt++;
            else    cnt--;
            if (cnt == 0) {
                num = nums[++i];
                cnt = 1;
            }
            i++;
        }
        return num;
    }
};