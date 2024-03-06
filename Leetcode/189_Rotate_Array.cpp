#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        /* Normal way */
        // for (int i = 0; i < k; i++)
        // {
        //     int val = nums[nums.size() - 1];
        //     nums.insert(nums.begin(), val);
        //     nums.pop_back();
        // }
        /* Optimize way */
        // in case k > n
        int n = nums.size();
        k %= n;

        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
private:
    void reverseArray(vector<int>&arr, int start, int end)
    {
        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    obj.rotate(nums, k);

    for (int num : nums)
    {
        std::cout << num << " ";
    }

    return 0;
}