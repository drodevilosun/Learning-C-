#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string letter) {
        bool res = true;
        string letter_comp;

        for (char s : letter) {
            if (std::isalnum(s)) {
                letter_comp += std::tolower(s);
            }
        }
        int n = letter_comp.size() - 1;
        if (n != 0)
        {
            int i;
            for (i = 0; i < letter_comp.size(); i++)
            {
                if (letter_comp[i] != letter_comp[n - i])
                    break;
            }
            if (i != n + 1)
                res = false;
        }
        return res;

        // GPT way
        // for (char c : letter) {
        //     if (std::isalnum(c)) {
        //         letter_comp += std::tolower(c);
        //     }
        // }

        // int left = 0;
        // int right = letter_comp.length() - 1;
        // while (left < right) {
        //     if (letter_comp[left] != letter_comp[right]) {
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        // return true;
    }

};

int main()
{
    Solution obj;
    std::string letter = "race a car";
    bool output = obj.isPalindrome(letter);

    std::cout << output << std::endl;


    return 0;
}