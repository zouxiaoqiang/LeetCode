#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == tmp) {
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
        return ret;
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m.insert(map<int, int>::value_type(nums[i], i));
        for (int i = 0; i < nums.size(); i++)
            if (m.count(target - nums[i]) > 0 && m[target - nums[i]] != i) {
                ret[0] = i;
                ret[1] = m[target - nums[i]];
                return ret;
            }

        return ret;
    }
};

int main() { return 0; }