
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n_cnt = 0;
        for (int i = m; i < m + n; i++, n_cnt++)
        {
            nums1[i] = nums2[n_cnt];
        }

        sort(nums1.begin(), nums1.end());
    }
};