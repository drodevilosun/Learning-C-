#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_sub = INT_MAX;
        int left = 0, right = 0;
        int n = nums.size();
        int sum = nums[left];
        while (right < n) {
            if (left < right)
                sum += nums[right];

            while (sum >= target && left <= right) {
                min_sub = min(min_sub, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (min_sub == INT_MAX)
            min_sub = 0;
        return min_sub;
    }
    // short way
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int left = 0;
    //     int right = 0;
    //     int min_len = INT_MAX;
    //     int window_sum = 0;
    //     while (right < nums.size())
    //     {
    //         window_sum += nums[right];
    //         while (window_sum >= target)
    //         {
    //             min_len = min(min_len, right - left + 1);
    //             window_sum -= nums[left];
    //             left++;
    //         }
    //         right++;
    //     }
    //     if (min_len == INT_MAX)
    //         return 0;
    //     return min_len;
    // }
};

int main()
{
    Solution obj;
    vector<int> nums = {1,4,4};
    int target = 4;
    int output = obj.minSubArrayLen(target, nums);

    cout << "output is: " << output << endl;

    return 0;
}
