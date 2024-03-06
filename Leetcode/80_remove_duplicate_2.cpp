#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for (auto it = nums.begin(); it != nums.end() - 1; it++)
        {
            if (*it == *(it + 1))
            {
                cnt++;
                if (cnt >= 2)
                {
                    nums.erase(it);
                    it--;
                }
            }
            else
                cnt = 0;
        }
        // nums.erase(unique(nums.begin(), nums.end(), nums.end()));
        return nums.size();
    }
};