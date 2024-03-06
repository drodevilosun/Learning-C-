#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // way 1: simple way
    // int lengthOfLongestSubstring(string s) {
    //     string substring;
    //     int max_sub = 0;
    //     int left = 0;
    //     int right = 0;
    //     while (right < s.length())
    //     {
    //         int res = substring.find(s[right]);
    //         if (res == -1)
    //             substring += s[right];
    //         else {
    //             while (left < right && substring.find(s[right]) != -1)
    //             {
    //                 int size = substring.length();
    //                 max_sub = max(max_sub, size);
    //                 // max_sub = right - left + 1;
    //                 left++;
    //                 if (left < right)
    //                     substring = substring.substr(1, substring.length());
    //                 else
    //                     substring = "";
    //             }
    //             substring += s[right];
    //         }
    //         right++;
    //     }
    //     int size = substring.length();
    //     max_sub = max(max_sub, size);
    //     return max_sub;
    // }

    // way 2: Using unordered_set
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLenght = 0;
        unordered_set<char> charSet;

        while (right < s.length())
        {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLenght = max(maxLenght, right - left + 1);
                right++;
            }
            else
            {
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLenght;
    }
};



int main()
{
    Solution obj;
    string s = "bbbbb";
    int out = obj.lengthOfLongestSubstring(s);

    cout << "Output is: " << out << endl;

    return 0;
}