#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // way 1 Hh
    int findMinArrowShots(vector<vector<int>>& points) {
        int num_arrow = 0;
        if (points.size() == 1)
            return 1;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[1] < b[1]);
        });

        int left = 0;
        int right = 1;
        while(right < points.size())
        {
            if (points[left][1] >= points[right][0])
                right++;
            else {
                num_arrow++;
                left = right;
                right++;
            }
        }
        num_arrow++;
        return num_arrow;
    }

    // way 2 GPT
    // int findMinArrowShots(vector<vector<int>>& points) {
    //     if (points.empty()) {
    //         return 0;
    //     }

    //     // Sort balloons based on ending points
    //     sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
    //         return a[1] < b[1];
    //     });

    //     int arrows = 1;
    //     int prevEnd = points[0][1];

    //     for (int i = 1; i < points.size(); ++i) {
    //         if (points[i][0] > prevEnd) {
    //             // Need a new arrow
    //             arrows++;
    //             prevEnd = points[i][1];
    //         }
    //     }

    //     return arrows;
    // }
};

int main()
{
    vector<vector<int>> points = 
                                // {{1,6},{2,8},{7,12},{10,16}};
                                // {{1,2},{2,3},{2,4},{4,5}};
                                {{0,9},{0,6},{2,9},{2,8},{3,9},{3,8},{3,9},{6,8},{7,12},{9,10},{8,8}};
                                // {{-2147483646,-2147483645},{2147483646,2147483647}};
    Solution obj;
    int output = obj.findMinArrowShots(points);

    std::cout << "Output is: " << output << std::endl;
    return 0;
}
