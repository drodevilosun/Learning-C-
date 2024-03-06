#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        int farthest = 0; // The farthest index that can be reached

        for (int i = 0; i < nums.size(); ++i) {
            // If the current index is not reachable, return false
            if (i > farthest) {
                return false;
            }

            // Update the farthest index that can be reached
            farthest = std::max(farthest, i + nums[i]);

            // If the last index is reachable, return true
            if (farthest >= nums.size() - 1) {
                return true;
            }
        }

        return false; // The last index is not reachable
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {2,5,0,0};
    bool output = obj.canJump(nums);

    std::cout << output << std::endl;


    return 0;
}