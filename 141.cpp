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
    bool hasCycle(ListNode *head) {
        ListNode *curFast = head, *curSlow = head;
        while (curFast && curFast->next) {
            curFast = curFast->next->next;
            curSlow = curSlow->next;
            if (curFast == curSlow)
                return true;
        }
        return false;
    }
};

