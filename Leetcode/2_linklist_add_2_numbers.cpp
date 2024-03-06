#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int x, ListNode *next_ptr) {
        val = x;
        next = next_ptr;
    }
};

class Solution {
public:
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode *res = nullptr;
    //     ListNode *next = nullptr;
        
    //     int mem = 0;
    //     while (l1 != nullptr || l2 != nullptr) {
    //         int sum = 0;
    //         if (l1 != nullptr && l2 != nullptr) {
    //             sum = l1->val + l2->val + mem;
    //             l1 = l1->next;
    //             l2 = l2->next;
    //         }
    //         else if (l1 != nullptr) {
    //             sum = l1->val + mem;
    //             l1 = l1->next;
    //         }
    //         else if (l2 != nullptr) {
    //             sum = l2->val + mem;
    //             l2 = l2->next;
    //         }
    //         mem = 0;
    //         if (sum >= 10) {
    //             sum = sum - 10;
    //             mem = 1;
    //         }
    //         if (res) {
    //             next->next = new ListNode(sum);
    //             next = next->next;
    //         }
    //         else {
    //             res = new ListNode(sum);
    //             next = res;
    //         }
    //     }
    //     return res;
    // }

    // Shorter code
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr;
        ListNode *current_node = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            if (res) {
                current_node->next = new ListNode(sum % 10);
                current_node = current_node->next;
            }
            else {
                res = new ListNode(sum % 10);
                current_node = res;
            }
        }
        return res;
    }
};

int main ()
{
    ListNode *l1 = nullptr;
    l1 = new ListNode(3, l1);
    l1 = new ListNode(4, l1);
    l1 = new ListNode(2, l1);
    ListNode *l2 = nullptr;
    l2 = new ListNode(4, l2);
    l2 = new ListNode(6, l2);
    l2 = new ListNode(5, l2);

    Solution obj;
    ListNode *output = obj.addTwoNumbers(l1, l2);

    return 0;
}
