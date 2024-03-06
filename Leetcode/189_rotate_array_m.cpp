#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     if (nums.size() == 1)
    //         return;
    //     int n = k > nums.size() ? k % nums.size() : k;
    //     for (int i = 0; i < n; i++)
    //     {
    //         nums.insert(nums.begin(), nums.back());
    //         nums.erase(nums.end() -1);
    //     }
    // }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
private:
    void reverseArray(vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    } 
};

int main()
{
    Solution obj;
    int k = 3;
    vector<int> nums = {1,2,3,4,5,6,7};
    obj.rotate(nums, k);

    cout << "Finish" << endl;

    return 0;
}
