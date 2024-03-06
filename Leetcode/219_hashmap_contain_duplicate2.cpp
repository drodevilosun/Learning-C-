#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool res = false;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            if (indices.find(nums[i]) != indices.end())
            {
                if (abs(i - indices[nums[i]]) <= k)
                    return true;
            }
            indices[nums[i]] = i;
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;

    bool output = obj.containsNearbyDuplicate(nums, k);
    std::cout << "contain duplicate: " << output << std::endl;

    return 0;
}
