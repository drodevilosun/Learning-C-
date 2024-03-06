#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())        
            return false;
        unordered_map<char, char> sToMap;
        unordered_map<char, char> tToMap;
        for (int i = 0; i < s.length(); i++)
        {
            char sChar = s[i];
            char tChar = t[i];
            if (sToMap.find(sChar) == sToMap.end() && tToMap.find(tChar) == tToMap.end())
            {
                sToMap[sChar] = tChar;
                tToMap[tChar] = sChar;
            }
            else if (sToMap[sChar] != tChar || tToMap[tChar] != sChar)
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    string s = "badc";
    string t = "baba";

    bool output = obj.isIsomorphic(s, t);
    std::cout << "can construct: " << output << std::endl;

    return 0;
}
