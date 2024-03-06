#include <iostream>
#include <vector>
#include <algorithm>

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
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int x, ListNode *next_ptr) {
        val = x;
        next = next_ptr;
    }
};

class Solution {
public:
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if (lists.size() == 0)
    //         return NULL;
    //     ListNode *res, *head, *tail;
    //     int node_size = 0;
    //     while (node_size < lists.size() && lists[node_size] == NULL)
    //         node_size++;
    //     if (node_size == lists.size())
    //         return NULL;
    //     head = lists[node_size];
    //     tail = lists[node_size];
    //     res = head;
    //     while (tail != NULL && tail->next != NULL) {
    //         tail = tail->next;
    //     }
    //     for (int i = node_size + 1; i < lists.size(); i++) {
    //         ListNode *child = lists[i];
    //         if (child != NULL)
    //         {
    //             tail->next = child;
    //             while (tail != NULL && tail->next != NULL) {
    //                 tail = tail->next;
    //             }
    //         }
    //     }
    //     tail = head;
    //     while (head != NULL) {
    //         tail = head;
    //     while (tail != NULL) {
    //         if (head->val > tail->val)
    //             swap(head->val, tail->val);
    //         tail = tail->next;
    //     }
    //     head = head->next;
    //     }
        
    //     return res;
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i]) {
                nums.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }            
        }
        sort(nums.rbegin(), nums.rend());
        ListNode *res = nullptr;
        for (int i = 0; i < nums.size(); i++) {
            res = new ListNode(nums[i], res);
        }
        return res;
    }
};

int main() {
    // Example usage:
    // [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode*> lists;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);
    lists.push_back(head);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    lists.push_back(head2);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);
    lists.push_back(head3);

    // [[],[1]]
    // vector<ListNode*> lists;
    // ListNode* head = new ListNode(1);
    // ListNode* head1 = new ListNode(0);
    // lists.push_back(head);
    // lists.push_back(head1);
    
    Solution obj;
    ListNode *node = obj.mergeKLists(lists);
    std::cout << "FInish" << std::endl;


    return 0;
}