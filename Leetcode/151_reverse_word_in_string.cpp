#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string output;

        s = ' ' + s + ' ';
        int left = 0;
        int right = s.length() - 1;
        int space_pos = right;
        for (int i = right - 1; i >= left; i--)
        {
            if (s[i] == ' ' && s[i + 1] != ' ' || i == left)
            {
                output += s.substr(i + 1, right - i - (right - space_pos));
            }
            if (s[i] == ' ')
                space_pos = i;
        }

        // remove leading and trailing spaces form output
        left = 0;
        right = output.length() - 1;
        while (left < right && output[left] == ' ')
            left++;
        while (left < right && output[right] == ' ')
            right--;
        output = output.substr(left, right + 1);
        return output;
    }
};

int main()
{
    Solution obj;
    // string s = "the sky is blue";
    string s = "  hello world  ";
    string output = obj.reverseWords(s);

    cout << "output is: " << output << endl;

    return 0;
}
