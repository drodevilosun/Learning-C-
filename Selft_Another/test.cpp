#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int main() {
//     std::vector<int> nums1 = {1, 2};
//     std::vector<int> nums2 = {2, 1};

//     bool sorted1 = std::is_sorted(nums1.begin(), nums1.end());
//     bool sorted2 = std::is_sorted(nums2.begin(), nums2.end());

//     std::cout << "nums1 is sorted: " << std::boolalpha << sorted1 << std::endl;
//     std::cout << "nums2 is sorted: " << std::boolalpha << sorted2 << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <algorithm>

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// int maxDepth(TreeNode* root) {
//     if (root == nullptr) {
//         return 0; // Base case: empty subtree has depth 0
//     }

//     // Recursively calculate the depth of left and right subtrees
//     int leftDepth = maxDepth(root->left);
//     int rightDepth = maxDepth(root->right);

//     // Return the maximum depth of the two subtrees plus one for the current node
//     return 1 + std::max(leftDepth, rightDepth);
// }

// int main() {
//     // Example binary tree: (1) -> (2) -> (3)
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->left->left = new TreeNode(3);

//     int depth = maxDepth(root);
//     std::cout << "Maximum depth of the binary tree: " << depth << std::endl;

//     int i = 1;
//     while (i != 1)
//     {
//         i++;
//     }
//     std::cout << i << std::endl;
    

//     return 0;
// }

/* lvalue rvalue */
// void foo(auto&& a)
// {
//     //Some magical code...
//     std::cout << "a is: " << a;
// }

// int main()
// {
//     int b;
//     foo(b); //Error. An rValue reference cannot be pointed to a lValue.
//     foo(5); //Compiles with no error.
//     foo(b+3); //Compiles with no error.

//     int&& c = b; //Error. An rValue reference cannot be pointed to a lValue.
//     int&& d = 5; //Compiles with no error.

//     int i = 42;
//     foo(i);
// }

/* shift bit */

// #include <iostream>

// void reverse_bit(unsigned char &binary ,int bit)
// {
//     binary ^= (1 << bit);
// }

// int main() {
//     // Original binary: 11101101
//     unsigned char binary = 0xED;  // Hexadecimal representation of 11101101

//     // Reverse bit 4 (1-based index)
//     // binary ^= (1 << 3);  // Reverse bit 4
//     reverse_bit(binary, 3);
//     reverse_bit(binary, 5);
//     reverse_bit(binary, 1);

//     // Print the result in binary format
//     for (int i = 7; i >= 0; i--) {
//         std::cout << ((binary & (1 << i)) ? 1 : 0);
//     }
//     std::cout << std::endl;

//     return 0;
// }

// 11101101
// 11100101

int &createInt() {
    int my_int = 10;
    return my_int;
}

int main()
{
    // int& my_int = createInt();
    int b = 10;
    int& data_int = b;
    cout << data_int << endl;

    return 0;
}
