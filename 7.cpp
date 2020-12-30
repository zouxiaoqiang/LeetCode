#include <iostream>
using namespace std;
class Solution {
   public:
    int reverse(int x) {
        long tmp = 0, sum = 0;
        while (x != 0) {
            tmp = x % 10;
            sum = sum * 10 + tmp;
            x /= 10;
        }
        if (sum < INT_MIN || sum > INT_MAX)
            sum = 0;
        return sum;
    }
};