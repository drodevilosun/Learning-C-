#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> sToMap;
        unordered_map<char, int> tToMap;
        for (char c: s)
        {
            sToMap[c]++;
        }
        for (char c: t)
        {
            tToMap[c]++;
        }
        for (auto it = sToMap.begin(); it != sToMap.end(); it++)
        {
            if (it->second != tToMap[it->first])
                return false;
        }
        return true;
    }
};


int main() {
    Solution obj;
    string s = "anagram";
    string t = "nagaram";

    bool output = obj.isAnagram(s, t);
    std::cout << "Ouput is: " << output << std::endl;

    return 0;
}
