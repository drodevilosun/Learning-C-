#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.empty())
            return "";
        string lcp = strs[0];
        
        for (int i = 1; i < n; i++)
        {
            int j = 0;
            while(j < lcp.length() && j < strs[i].length()  && lcp[j] == strs[i][j])
            {
                j++;
            }
            lcp = strs[i].substr(0, j);
        }
        return lcp;
    }
};

int main()
{
    Solution obj;
    vector<string> strs = {"dog","racecar","car"};
    string output = obj.longestCommonPrefix(strs);

    cout << "output is: " << output << endl;

    return 0;
}
