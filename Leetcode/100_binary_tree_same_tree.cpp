#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        
        if (p != nullptr && q != nullptr)
        {
            bool val = p->val == q->val;
            bool left  = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);
            return val & left & right;
        }

        return false;
    }
};

int main() {
    // Example binary tree: (1) -> (2) -> (3)
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    Solution obj;

    bool res = obj.isSameTree(root1, root2);
    std::cout << "is the same binary tree: " << res << std::endl;

    return 0;
}