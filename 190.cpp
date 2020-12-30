//
// Created by zxqnh on 2020/11/8.
//

#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, power = 31;
        while (n != 0) {
            ans += (n & 1) << power;
            power--;
            n >>= 1;
        }
        return ans;
    }
};

