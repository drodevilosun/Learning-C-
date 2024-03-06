#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty())
            return res;

        sort(intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] < b[0];
        });

        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> intervals = 
                                    // {{1,3},{2,6},{8,10},{15,18}};
                                    // {{1,3},{2,2},{8,10},{15,18}};
                                    // {{2,2}};
                                    {{1,4},{0, 0}};
                                    // {{1,4},{1,4}};
    Solution obj;
    vector<vector<int>> output = obj.merge(intervals);

    return 0;
}