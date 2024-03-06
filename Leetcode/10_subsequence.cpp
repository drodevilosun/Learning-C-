#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isSubsequence(string src, string des) {
        bool res = false;
        auto it_c = src.begin();
        for (int i = 0; i < des.length(); i++)
        {
            if (*it_c == des[i])
            {
                *it_c++;
            }
        }
        if (it_c == src.end())
            res = true;
        return res;
    }
};

int main()
{
    Solution obj;
    std::string src = "abc";
    std::string des = "ahbgdc";
    bool output = obj.isSubsequence(src, des);

    std::cout << output << std::endl;


    return 0;
}