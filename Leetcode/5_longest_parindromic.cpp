#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // My way
    string res;
    string longestPalindrome(string s) {
        
        for (int i = 0; i < s.length() - 1; i++) {
            expand_string(s, i, i);
            expand_string(s, i, i + 1);
        }

        return res;
    }
private:
    void expand_string(string s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right])
                break;
            left--;
            right++;
        }
        if (res.length() < right - left)
            res = s.substr(left + 1, right - left - 1);
    }

    // GPT way
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     if (n < 2) return s;
    //     vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    //     int start = 0, maxLen = 1;
    //     // All substrings of length 1 are palindromes
    //     for (int i = 0; i < n; i++) {
    //         isPalindrome[i][i] = true;
    //     }
    //     // Check for substrings of length 2
    //     for (int i = 0; i < n - 1; i++) {
    //         if (s[i] == s[i + 1]) {
    //             isPalindrome[i][i + 1] = true;
    //             start = i;
    //             maxLen = 2;
    //         }
    //     }
    //     // Check for substrings of length 3 or more
    //     for (int len = 3; len <= n; len++) {
    //         for (int i = 0; i <= n - len; i++) {
    //             int j = i + len - 1;

    //             if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
    //                 isPalindrome[i][j] = true;
    //                 if (len > maxLen) {
    //                     start = i;
    //                     maxLen = len;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(start, maxLen);
    // }

    // optimize way
    // string ans = "";
    // void expand(string &s , int left ,int right)
    // {
    //     while(left >= 0 &&  right < s.size())
    //     {
    //         if(s[left] != s[right])
    //             break;
    //         left--,right++;
    //     }
    //     if(ans.size() < right - left )
    //         ans = s.substr(left + 1 , right - left - 1);
    // }
    // string longestPalindrome(string s) {
    //     for(int i = 0 ; i < s.size() ; i++)
    //     {
    //         expand(s , i , i);
    //         expand(s , i , i+1);
    //     }
    //     return ans;
    // }
};

int main()
{
    Solution obj;
    // string s = "cbad";
    string s = "cbabaababd";
    string output = obj.longestPalindrome(s);

    std::cout << output << std::endl;


    return 0;
}