#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& lines) {
        int left = 0;
        int right = lines.size() - 1;
        int container = 0;
        while (left < right) {
            int distance = right - left;
            int water;
            if (left < right) {
                water = lines[left] * distance;
                left++;
            }
            else if (right <= left) {
                water = lines[right] * distance;
                right--;
            }
            container = max(water, container);
        }

        return container;
    }
};

int main()
{
    Solution obj;
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int output = obj.maxArea(nums);

    std::cout << output << std::endl;


    return 0;
}