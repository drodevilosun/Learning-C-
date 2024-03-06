#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // comunity way
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }

        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
    // my way not cover all cases
    // string minWindow(string s, string t) {
    //     int num_t = t.length();
    //     int min_size = INT_MAX;
    //     int left = 0, right = 0;
    //     string subs;
    //     string tmp = t;
    //     if (s.length() < t.length())
    //         return "";
    //     while (right < s.length())
    //     {
    //         bool is_match = false;
    //         for (int i = 0; i < num_t; i++)
    //         {
    //             if (s[right] == tmp[i] && num_t == t.length())
    //             {
    //                 left = right;
    //                 tmp.erase(i, 1);
    //                 is_match = true;
    //                 break;
    //             }
    //             else if (s[right] == tmp[i])
    //             {
    //                 is_match = true;
    //                 tmp.erase(i, 1);
    //                 break;
    //             }
    //         }
    //         if (is_match == true)
    //             num_t--;
    //         if (num_t == 0) {
    //             if (min_size > (right - left + 1)) {
    //                 min_size = right - left + 1;
    //                 subs = s.substr(left, min_size);
    //             }
    //             if (right + 1 < s.length() && s[right] == s[right + 1])
    //                 right++;
    //             else if (right + 1 == s.length())
    //                 break;

    //             left = right;
    //             num_t = t.length();
    //             tmp = t;
    //             continue;
    //         }
    //         right++;
    //     }
    //     return subs;
    // }

    // GPT way failed with eceed memory
    // string minWindow(string s, string t) {
    //     unordered_map<char, int> charCountT, charCountWin;

    //     for (char c : t)
    //         charCountT[c]++;

    //     int left = 0, right = 0;
    //     int num_char_t = charCountT.size();
    //     int found_char = 0;
    //     int min_size = INT_MAX;
    //     string subs;

    //     while (right < s.length())
    //     {
    //         char s_char = s[right];
            
    //         charCountWin[s_char]++;
    //         if (charCountT.find(s_char) != charCountT.end() && charCountWin[s_char] == charCountT[s_char])
    //         {
    //             found_char++;
    //         }
    //         while (found_char == num_char_t && left <= right)
    //         {
    //             if (right - left + 1 < min_size)
    //             {
    //                 min_size = right - left + 1;
    //                 subs = s.substr(left, min_size);
    //             }

    //             char left_char = s[left];
    //             charCountWin[left_char]--;
    //             if (charCountT.find(left_char) != charCountT.end() && charCountWin[left_char] < charCountT[left_char])
    //                 found_char--;
                
    //             left++;
    //         }
    //         right++;
    //     }
    //     return subs;
    // }
};

int main()
{
    Solution obj;
    // string s = "ADOBECODEBANC", t = "ABC";
    string s = "bdab", t = "ab";
    // string s = "aa", t = "a";

    string output = obj.minWindow(s,t);

    cout << "output is: " << output << endl;

    return 0;
}