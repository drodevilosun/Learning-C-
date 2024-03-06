#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currEnd = 0;
        int maxReachable = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxReachable = max(maxReachable, i + nums[i]);
            if (i == currEnd)
            {
                currEnd = maxReachable;
                jumps++;
            }
        }
        return jumps;
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {2,5,0,0};
    bool output = obj.jump(nums);

    std::cout << output << std::endl;


    return 0;
}