//
// Created by zxqnh on 2020/11/22.
//
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int buffer[] = {1, 2, 3, 4, 5, 6};
    int buflen = 6;
    int shift = 2;
    int i;
    int itemp;
    int *d, *p;
    p = new int[buflen + 2 * shift];
    cout << buflen + 2 * shift << endl;
    d = new int[(buflen >> 1) + shift];
    /*  对称延拓 */
    for (i = 0; i < shift; i++) {
        *(p + i) = *(buffer + shift - i);
        *(p + buflen + shift + i) = *(buffer + buflen - i - 2);
    }
    for (i = 0; i < buflen; i++) *(p + i + shift) = *(buffer + i);
    /* 数据延拓结束  计算p1 = d1          p2 = s1 */

    for (i = 0; i < (buflen >> 1) + shift; i++) {
        itemp = i - (shift >> 1);
        *(d + i) = *(p + shift + 2 * itemp + 1) -
                   int(floor(*(p + shift + 2 * itemp + 2) / 2. + *(p + shift + 2 * itemp) / 2. + 0.5));
        cout << p[shift + 2 * itemp + 2] << endl;

    }
    for (i = 0; i < (buflen >> 1); i++) {
        *(buffer + (buflen >> 1) + i) = *(d + i + (shift >> 1));
        *(buffer + i) =
                *(p + shift + 2 * i) + int(floor(*(d + i + (shift >> 1)) / 4. + *(d + i - 1 + (shift >> 1)) / 4. + 1));
    }
    delete[]p;
    delete[]d;
    return 0;
}

