#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int res = 1;
        int tmp = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 == nums[i - 1])
                tmp += 1;
            else if (nums[i] == nums[i-1])
                continue;
            else {
                res = max(tmp, res);
                tmp = 1;
            }
        }
        res = max(tmp, res);

        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int output = obj.longestConsecutive(nums);

    cout << "output is: " << output << endl;

    return 0;
}
