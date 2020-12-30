//
// Created by zxqnh on 2020/11/8.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for (int i = 5; i <= n; i++) {
            int j = i;
            while (j > 0 && j % 5 == 0) {
                cnt++;
                j /= 5;
            }
        }
        return cnt;
    }
};

