#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1 && inorder.size() == 1)
            return root;

        int left_size = 0;
        for (; left_size < inorder.size(); left_size++)
        {
            if (root->val == inorder[left_size])
                break;
        }
        // build left tree node
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> inorder_left(inorder.begin(), inorder.begin() + left_size);
        root->left = buildTree(preorder_left, inorder_left);

        // build right tree node
        vector<int> preorder_right(preorder.begin() + 1 + left_size, preorder.end());
        vector<int> inorder_right(inorder.begin() + left_size + 1, inorder.end());
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }

    /**
     * Cách này nhanh hơn cách trên và tốn ít memory hơn cách trên vì:
     * Save memory: Nó dùng lại các vector gốc và thêm vào chỉ số preStart và inStart để giảm thiểu tạo mới vector
     * Faster: Vì nó allocate 1 unordered_map để looking for left tree size instead of using for loop -> faster
     */
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& inorderIdx) {
        if (preStart >= preorder.size() || inStart > inEnd) {
            return nullptr; // Base case: Empty subtree
        }

        int rootVal = preorder[preStart];
        int inRootIdx = inorderIdx[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, inRootIdx - 1, inorderIdx);
        root->right = buildTreeHelper(preorder, inorder, preStart + inRootIdx - inStart + 1, inRootIdx + 1, inEnd, inorderIdx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIdx;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIdx[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1, inorderIdx);
    }

    // Helper function to print the binary tree using inorder traversal
    void inorderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
};

int main() {
    // Example binary tree: (1) -> (2) -> (3)
    
    Solution obj;
    // vector<int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    TreeNode *tree = obj.buildTree(preorder, inorder);
    // std::cout << "Maximum depth of the binary tree: " << depth << std::endl;
    obj.inorderTraversal(tree);
    return 0;
}