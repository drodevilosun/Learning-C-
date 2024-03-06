#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        return index;
    }
};


int main()
{
    Solution obj;
    string haystack = "butxad";
    string needle = "sad";
    int output = obj.strStr(haystack, needle);


    return 0;
}