
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        // there is no number in array match with target
        return {};
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {2,7,11,15};
    vector<int> output = obj.twoSum(nums, 9);

    // std::cout << output << std::endl;


    return 0;
}