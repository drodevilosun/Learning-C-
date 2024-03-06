#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // way 1
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     vector<vector<int>> res;
    //     if (intervals.empty())
    //         return {newInterval};
        
    //     vector<vector<int>> merged = intervals;
    //     merged.push_back(newInterval);
    //     sort(merged.begin(), merged.end(), [](const vector<int>& a, const vector<int> b) {
    //         return a[0] < b[0];
    //     });
    //     res.push_back(merged[0]);
    //     for (int i = 0; i < merged.size(); i++)
    //     {
    //         if (res.back()[1] >= merged[i][0])
    //         {
    //             res.back()[1] = max(res.back()[1], merged[i][1]);
    //         }
    //         else
    //         {
    //             res.push_back(merged[i]);
    //         }
    //     }

    //     return res;
    // }
    
    
    // way 2
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while (i < n && newInterval[0] > intervals[i][1])
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        // Merge newInterval into intervals
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};

int main()
{
    vector<vector<int>> intervals = 
                                    // {{1,3},{6, 9}};
                                    {{1,2},{3,5}, {6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    Solution obj;
    vector<vector<int>> output = obj.insert(intervals, newInterval);

    return 0;
}