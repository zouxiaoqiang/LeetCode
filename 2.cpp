#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1);
        ListNode *cur = ret;
        int sum, carry = 0;
        while (l1 || l2) {
            sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
        }
        if (carry == 1) {
            cur->next = new ListNode(carry);
        }
        return ret->next;
    }

    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        int len1 = 1, len2 = 1;
        ListNode *cur1 = l1, *cur2 = l2;
        while (cur1->next) {
            len1++;
            cur1 = cur1->next;
        }
        while (cur2->next) {
            len2++;
            cur2 = cur2->next;
        }
        if (len1 < len2) {
            for (int i = 0; i < len2 - len1; i++) {
                cur1->next = new ListNode(0);
                cur1 = cur1->next;
            }
        }
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                cur2->next = new ListNode(0);
                cur2 = cur2->next;
            }
        }
        int carry = 0, val;
        ListNode *ret = new ListNode(-1), *cur = ret;
        while (l1) {
            val = l1->val + l2->val + carry;
            carry = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (carry == 1) {
            cur->next = new ListNode(1);
        }
        return ret->next;
    }
};