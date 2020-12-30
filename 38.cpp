#include <sstream>
#include <string>
using namespace std;
class Solution {
   public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; i++) {
            int j = 0;
            ostringstream oss;
            while (j < s.length()) {
                char c = s[j++];
                int cnt = 1;
                for (; j < s.length() && c == s[j]; j++) cnt++;
                oss << cnt << c;
            }
            s = oss.str();
        }
        return s;
    }
};