#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool res = true;
        unordered_map<char, int> u_magazine;
        for (char c: magazine)
            u_magazine[c]++;

        for (char c: ransomNote)
        {
            if (u_magazine[c] != 0)
            {
                u_magazine[c]--;
            }
            else
            {
                res = false;
                break;
            }
        }

        return res;
    }
};


int main() {
    Solution obj;
    string ransomNote = "aad";
    string magazine = "aabx";

    bool output = obj.canConstruct(ransomNote, magazine);
    std::cout << "can construct: " << output << std::endl;

    return 0;
}

