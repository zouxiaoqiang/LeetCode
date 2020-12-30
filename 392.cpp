//
// Created by zxqnh on 2020/11/17.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0, size_s = s.size(), size_t = t.size();
        for (int ti = 0; ti < size_t; ti++) {
            if (s[si] == t[ti]) {
                si++;
                if (si == size_s) break;
            }
        }
        return si == size_s;
    }

    // 动态规划, 对t做预处理，可以迅速地处理任意的s
    bool isSubsequence1(string s, string t) {
        int size_t = t.size(), size_s = s.size();
        int f[size_t + 1][26];
        for (int i = 0; i < 26; i++) f[size_t][i] = size_t;
        for (int i = size_t - 1; i >= 0; i++) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == 'a' + j) f[i][j] = i;
                else f[i][j] = f[i + 1][j];
            }
        }
        int add = 0;
        for (int i = 0; i < size_s; i++) {
            if (f[add][s[i] - 'a'] == size_t)
                return false;
            else
                add = f[add][s[i] - 'a'] + 1;
        }
        return true;
    }
};

