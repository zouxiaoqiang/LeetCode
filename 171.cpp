//
// Created by zxqnh on 2020/11/8.
//
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        string::size_type size = s.size();
        int sum = 0;
        for (string::size_type i = 0; i < size; i++)
            sum = s[i] - 'A' + 1 + sum * 26;
        return sum;
    }
};
