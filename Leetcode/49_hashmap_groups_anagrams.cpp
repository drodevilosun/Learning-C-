#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramGroup;
        for (string s : strs)
        {
            string canonical = s;
            sort(canonical.begin(), canonical.end());
            anagramGroup[canonical].push_back(s);
        }

        for (auto &it = anagramGroup.begin(); it != anagramGroup.end(); it++)
        {
            result.push_back(it->second);
        }

        return result;
    }
};

