#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // int lengthOfLastWord(string s) {
    //     int n = s.size();
    //     bool is_last_word = false;
    //     int word_length = 0;
    //     for(int i = n - 1; i >= 0; i--)
    //     {
    //         if (s[i] != ' ')
    //             is_last_word = true;
    //         if (is_last_word == true && s[i] != ' ')
    //             word_length += 1;
    //         else if (is_last_word == true && s[i] == ' ')
    //             break;
    //     }
    //     return word_length;
    // }
    
    // Method 2
    int lengthOfLastWord(string s) {
        int n = s.size();
        int word_length = 0;
        // Trim leading and trailing spaces
        int left = 0;
        int right = n - 1;
        while (left < right && s[left] == ' ')
            left++;
        while (left < right && s[right] == ' ')
            right--;

        for (int i = right; i >= left; i--)
        {
            if (s[i] == ' ') {
                word_length = i;
                break;
            }
        }

        if (word_length == 0)
        {
            return word_length = right - left + 1;
        }

        return right - word_length;
    }
};

int main()
{
    Solution obj;
    string s = "world";
    obj.lengthOfLastWord(s);


    return 0;
}