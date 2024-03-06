#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& lines) {
        int n = lines.size();
        int left = 0;
        int right = n - 1;
        int max_water = 0;
        while (left < right)
        {
            if (lines[left] <= lines[right])
            {
                max_water = max(max_water, lines[left] * (right - left));
                left++;
            }
            else if (lines[left] > lines[right])
            {
                max_water = max(max_water, lines[right] * (right - left));
                right--;
            }
            // else
            // {
            //     if (left + 1 < right || right - 1 > left)
            //     {
            //         if (left)
            //     }
            // }
        }
    }
};