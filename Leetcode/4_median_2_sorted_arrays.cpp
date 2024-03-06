#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     double res = 0;
    //     double it_value = 0;
    //     int left1 = 0, left2 = 0, cnt = 0;
    //     int median = nums1.size() + nums2.size();
    //     bool is_even = median % 2 == 0 ? true : false;
    //     median /= 2;
    //     while (left1 < nums1.size() || left2 < nums2.size()) {
    //         if (left1 < nums1.size() && left2 < nums2.size()) {
    //             if (nums1[left1] < nums2[left2]) {
    //                 it_value = nums1[left1];
    //             }
    //             else {
    //                 it_value = nums2[left2];
    //             }
    //         }
    //         else if (left1 < nums1.size()) {
    //             it_value = nums1[left1];
    //         }
    //         else {
    //             it_value = nums2[left2];
    //         }

    //         if (left1 < nums1.size() && it_value == nums1[left1])
    //             left1++;
    //         else
    //             left2++;
            
    //         if (is_even == false) {
    //             if (left1 + left2 == (median + 1))
    //                 return it_value;
    //         }
    //         else {
    //             if (left1 + left2 >= median) {
    //                 res += it_value;
    //                 cnt++;
    //             }
    //             if (cnt == 2)
    //                 return res/2;
    //         }
    //     }
    //     return 0;
    // }

    // shorter solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for (int num1 : nums1)
            nums.push_back(num1);
        for (int num2 : nums2)
            nums.push_back(num2);
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return n%2 ? nums[n/2] : (nums[n/2 - 1] + nums[n/2])/2;
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2,6,9,11};
    double output = obj.findMedianSortedArrays(nums1, nums2);

    std::cout << output << std::endl;


    return 0;
}
