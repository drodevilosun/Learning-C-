#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *hare = head;
        ListNode *tortoies = head;
        while (hare && hare->next)
        {
            hare = hare->next->next;
            tortoies = tortoies->next;
            if (hare == tortoies)
            {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Example usage:
    // ListNode* head = new ListNode(3);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(-4);
    // head->next->next->next->next = head->next;  // Create a cycles

    ListNode* head = new ListNode(1);
    head->next = head;

    Solution obj;
    bool hasCycleResult = obj.hasCycle(head);
    std::cout << "Has Cycle: " << (hasCycleResult ? "true" : "false") << std::endl;

    // Don't forget to free the memory used by the list to prevent memory leaks.
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}