#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> numerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};


class Solution {
public:
    string intToRoman(int num)  {
        int romal_num = 0;
        string s;
        for (int i = 0; i < values.size(); i++)
        {
            while (num >= values[i])
            {
                s += numerals[i];
                num -= values[i];
            }
        }
        return s;
    }
};

int main()
{
    Solution obj;
    int number = 58;
    string roman_string = obj.intToRoman(number);

    cout << "roman number is: " << roman_string << endl;

    return 0;
}
