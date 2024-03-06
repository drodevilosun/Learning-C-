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
    bool isSymmetric(TreeNode* root) {
        
        if (root == nullptr)
            return true;
        else
            return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        bool res = false;
        if (left == nullptr && right == nullptr)
            res = true;
        else if (left != nullptr && right != nullptr) 
        {
            if (left->val == right->val)
            {
                bool res1 = isMirror(left->left, right->right);
                bool res2 = isMirror(left->right, right->left);
                res = res1 & res2;
            }
        }
        return res;
    }
};

int main() {
    // Example binary tree: (1) -> (2) -> (3)
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool output = obj.isSymmetric(root);
    std::cout << "is the symmetric binary tree: " << output << std::endl;

    return 0;
}