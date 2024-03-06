#include <iostream>
#include <string>
#include <map>

using namespace std;

std::map<char, int> RomanVal = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

class Solution {
public:
    int romanToInt(string roman) {
        int n = roman.length();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && RomanVal[roman[i]] < RomanVal[roman[i+1]])
            {
                sum += RomanVal[roman[i+1]] - RomanVal[roman[i]];
                i += 1;
            }
            else
                sum += RomanVal[roman[i]];
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    string letter = "LVIII";
    int value = obj.romanToInt(letter);

    cout << "roman number is: " << value << endl;

    return 0;
}
