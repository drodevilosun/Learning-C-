#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_left = 0;
        int max_right = 0;
        int sum = 0;

        if (n <= 2)
            return sum;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                max_left = max(height[left], max_left);
                sum += max_left - height[left];
                left++;
            }
            else
            {
                max_right = max(height[right], max_right);
                sum += max_right - height[right];
                right--;
            }
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trap_water = obj.trap(height);

    cout << "trap water is: " << trap_water << endl;

    return 0;
}
