#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // bool isValid(string s) {
    //     bool res = true;
    //     vector<char> parentheses;
    //     for (char c: s)
    //     {
    //         if (c == '{' || c == '[' || c == '(')
    //             parentheses.push_back(c);
    //         else if (parentheses.size() > 0 && c == ')') {
    //             if (parentheses.back() == '(') 
    //                 parentheses.pop_back();
    //             else
    //                 res = false;
    //         }
    //         else if (parentheses.size() > 0 && c == ']') {
    //             if (parentheses.back() == '[')
    //                 parentheses.pop_back();
    //             else
    //                 res = false;
    //         }
    //         else if (parentheses.size() > 0 && c == '}') {
    //             if (parentheses.back() == '{')
    //                 parentheses.pop_back();
    //             else
    //                 res = false;
    //         }
    //         else
    //         {
    //             res = false;
    //             break;
    //         }
    //     }
    //     if (parentheses.size() != 0)
    //         res = false;
    //     return res;
    // }

    // second method
    bool isValid(string s) {
        stack<char> parentheses;
        for (char c: s)
        {
            if (c == '{' || c == '[' || c == '(')
                parentheses.push(c);
            else {
                if (parentheses.empty())
                    return false;

                char top = parentheses.top();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{'))
                    parentheses.pop();
                else
                    return false;
            }
        }
        return parentheses.empty();
    }
};

int main()
{
    Solution obj;
    string parentheses = "[()]";
    bool output = obj.isValid(parentheses);

    cout << "result is: " << output << endl;
    return 0;
}

