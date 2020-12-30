//
// Created by zxqnh on 2020/10/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
            ans.emplace_back(i, 1);
        for (int i = 2; i < numRows; i++)
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        return ans;
    }
};
