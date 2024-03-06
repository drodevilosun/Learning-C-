#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end() - 1; it++)
        {
            if (*it == *(it + 1))
            {
                nums.erase(it);
                it--;
            }
        }
        // nums.erase(unique(nums.begin(), nums.end(), nums.end()));
        return nums.size();
    }
};