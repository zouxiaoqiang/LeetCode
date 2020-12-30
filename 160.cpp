//
// Created by zxqnh on 2020/10/25.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *la = headA, *lb = headB;
        int cnt = 0;
        while (cnt < 3) {
            if (la == lb) return la;
            la = la->next;
            lb = lb->next;
            if (la == NULL) {
                la = headB;
                cnt++;
            }
            if (lb == NULL) {
                lb = headA;
                cnt++;
            }
        }
        return NULL;
    }
};
