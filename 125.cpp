//
// Created by zxqnh on 2020/10/24.
//
#include <string>

using namespace std;

class Solution {
public:
    inline bool isAlphaNumeric(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');
    }

    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int left = 0, right = s.size() - 1;
        for (int i = 0; i <= right; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        while (left < right) {
            while (left < right && !isAlphaNumeric(s[left])) left++;
            while (left < right && !isAlphaNumeric(s[right])) right--;
            if (left < right && s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution s;
    s.isPalindrome("a.");
    return 0;
}

