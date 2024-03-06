#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int *a;
void test() {
    int b = 4;
    a = &b;
    cout << "inside test a is: " << a << endl;
    cout << "b address is: " << &b << endl;
}

class Solution {
public:
    vector<int> findMaxValue(vector<int>& nums) {
        int max_sum = nums[0];
        int curr_sum = nums[0];
        int left = 0, right = 0;
        for (int i = 1; i < nums.size(); i++) {
            // curr_sum = max(curr_sum + nums[i], nums[i]);
            // max_sum = max(curr_sum, max_sum);
            
            if (curr_sum + nums[i] > nums[i]) {
                curr_sum += nums[i];
            }
            else {
                left = i;
                right = i;
                curr_sum = nums[i];
            }
            if (max_sum < curr_sum) {
                right = i;
                max_sum = curr_sum;
            }
        }
        return {left, right};
    }
};

int main()
{
    test();

    cout << "outside test a is: " << a << endl;

    Solution obj;
    // vector<int> nums = {-2, 3 ,5 ,6, -10, 9};
    vector<int> nums = {3, -1, 9, -4, -5, -1, 4, 5};
    vector<int> output = obj.findMaxValue(nums);
    cout << "output is: " << output[0] << " " << output[1] << endl;

    return 0;
}

// 3  2 11  7    
// 3 -1 9  -4 -5 4 5

// 3 -1 9  -1 -1 4 -5

// 3  2 11


// 1 5 11
// 3 8 14
// -2, 3 ,5 ,6, -10, 9
//                r