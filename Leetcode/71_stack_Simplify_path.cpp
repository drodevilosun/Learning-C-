#include <stack>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string res;
        string word;
        stack<string> holder;
        while (getline(ss, word, '/'))
        {
            if (word == ".." && !holder.empty())
            {
                holder.pop();
            }
            else if (word != "." && word != ".." && !word.empty())
            {
                holder.push(word);
            }
        }

        while (!holder.empty())
        {
            res = "/" + holder.top() + res;
            holder.pop();
        }
        
        
        return res.empty() ? "/" : res;
    }
};



int main() {
    Solution obj;
    string path = "/../";
    string output = obj.simplifyPath(path);

    return 0;
} 