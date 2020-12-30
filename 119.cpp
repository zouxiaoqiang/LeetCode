//
// Created by zxqnh on 2020/10/24.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1), pre = ans;
        for (int i = 2; i <= rowIndex; i++) {
            ans = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[j] = pre[j - 1] + pre[j];
            }
            pre = ans;
        }
        return ans;
    }
};
