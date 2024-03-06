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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left  = tmp;
        tmp = nullptr;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};

int main() {
    // Example binary tree: (1) -> (2) -> (3)
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    TreeNode* new_tree = obj.invertTree(root);
    // std::cout << "is the same binary tree: " << res << std::endl;

    return 0;
}