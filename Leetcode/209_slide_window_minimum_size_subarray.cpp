#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int window_sum = 0;
        while (right < nums.size())
        {
            window_sum += nums[right];
            while (window_sum >= target)
            {
                min_len = min(min_len, right - left + 1);
                window_sum -= nums[left];
                left++;
            }
            right++;
        }
        if (min_len == INT_MAX)
            return 0;
        return min_len;
    }
};

int main() {
    Solution obj;
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    int output = obj.minSubArrayLen(target, nums);
    std::cout << "Min len is: " << output << std::endl;

    return 0;
}
