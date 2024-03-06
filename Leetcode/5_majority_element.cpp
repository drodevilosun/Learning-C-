#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(const std::vector<int>& nums) {
    int majorityElement = nums[0];
    int count = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == majorityElement) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            majorityElement = nums[i];
            count = 1;
        }
    }

    // At this point, majorityElement holds the potential majority element.
    // You may need to check if it appears more than n/2 times in the array.
    // It's a good idea to run another pass through the array to validate this.

    // Count the occurrences of majorityElement in the array.
    int majorityCount = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == majorityElement) {
            majorityCount++;
        }
    }

    // Check if majorityElement is indeed the majority element.
    if (majorityCount > nums.size() / 2) {
        return majorityElement;
    } else {
        // If there is no majority element, you may return an appropriate value or throw an exception.
        throw std::runtime_error("No majority element found.");
    }
}

int main() {
    // std::vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    std::vector<int> nums = {1, 2, 4, 5, 4, 4, 8, 4, 4};
    // std::vector<int> nums = {3,2,3};
    try {
        int majorityElement = findMajorityElement(nums);
        std::cout << "The majority element is: " << majorityElement << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int major_ele = nums[0];
        int major_cnt = 0;

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (major_ele == *it)
                cnt++;
            else
                cnt--;
            
            if (0 == cnt)
            {
                major_ele = *it;
                cnt = 1;
            }
        }

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (major_ele == *it)
                major_cnt++;
        }
        if (major_cnt > nums.size()/2)
            return  major_ele;
        else
            return 0;
    }
};