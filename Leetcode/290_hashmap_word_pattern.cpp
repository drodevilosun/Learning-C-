#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, string> pToMap;
        unordered_map<string, char> sToMap;
        
        int s_cnt = 0;
        for (int i = 0; i < s.length(); i ++)
        {
            if (s[i] == ' ')
                s_cnt++;
        }
        if (s_cnt + 1 != pattern.length())
            return false;
        // seperate s to multi words
        int p_cnt = 0;
        string word;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
                word += s[i];
            if (s[i] == ' ' || s.length() == i + 1) {
                if (pToMap.find(pattern[p_cnt]) == pToMap.end() && sToMap.find(word) == sToMap.end())
                {
                    pToMap[pattern[p_cnt]] = word;
                    sToMap[word] = pattern[p_cnt];
                }
                else if (pToMap[pattern[p_cnt]] != word || sToMap[word] != pattern[p_cnt])
                {
                    return false;
                }
                p_cnt++;
                word.clear();
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    string p = "abba";
    string t = "dog cat cat fish";

    bool output = obj.wordPattern(p, t);
    std::cout << "is word pattern: " << output << std::endl;

    return 0;
}
