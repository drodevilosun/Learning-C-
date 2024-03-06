#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // way 1
    // vector<string> summaryRanges(vector<int>& nums) {
    //     vector<string> output;
    //     int n = nums.size();
    //     if (n == 1)
    //     {
    //         string range = to_string(nums[0]);
    //         return {range};
    //     }
    //     int left = 0;
    //     int right = 0;
    //     while (right < n - 1)
    //     {
    //         if (nums[right] + 1 != nums[right + 1])
    //         {
    //             string range;
    //             if (left == right)
    //             {
    //                 range = to_string(nums[right]);
    //             }
    //             else
    //             {
    //                 range = to_string(nums[left]);
    //                 range += "->";
    //                 range += to_string(nums[right]);
    //             }
    //             output.push_back(range);
    //             left = right + 1;
    //         }

    //         if (n - 1 == right + 1)
    //         {
    //             string range;
    //             if (left == right + 1)
    //             {
    //                 range = to_string(nums[left]);
    //             }
    //             else
    //             {
    //                 range = to_string(nums[left]);
    //                 range += "->";
    //                 range += to_string(nums[right + 1]);
    //             }
    //             output.push_back(range);
    //         }
    //         right++;
    //     }
    //     return output;
    // }
    // way 2
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        int start = nums[0];
        int end = nums[0];
        vector<string> res;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == end + 1)
                end = nums[i];
            else
            {
                if (start == end)
                    res.push_back(to_string(end));
                else
                    res.push_back(to_string(start) + "->" + to_string(end));
                end = nums[i];
                start = nums[i];
            }
        }
        if (start == end)
            res.push_back(to_string(end));
        else
            res.push_back(to_string(start) + "->" + to_string(end));
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {-2147483648,-2147483647,2147483647};
    // vector<int> nums = {0,1,2,4,5,7};
    vector<string> output = obj.summaryRanges(nums);


    return 0;
}
