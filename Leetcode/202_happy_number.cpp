#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        bool res = false;
        unordered_set<int> recorded;
        while (n != 1 && recorded.find(n) == recorded.end())
        {
            recorded.insert(n);
            int sum = 0;
            while (n != 0)
            {
                int val_n = n % 10;
                n /= 10;
                sum += pow(val_n, 2);
            }
            n = sum;
        }
        if (n == 1)
            res = true;
        return res;
    }
};

int main()
{
    Solution obj;
    int n = 19;
    bool res = obj.isHappy(n);

    cout << res << endl;

    return 0;
}