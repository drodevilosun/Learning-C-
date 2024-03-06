#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
// public:
//     int reverse(int x) {
//         int max_int = INT_MAX;
//         if (x >= max_int || x <= -INT_MAX)
//             return 0;
//         int sign = x < 0 ? -1 : 1;
//         x *= sign;
//         string s_num = to_string(x);
        
//         if (s_num.length() >= 10) {
//             // int tmp = stoi(s_num.substr(9,1));
            
//             if (stoi(s_num.substr(9,1)) <= 2) {
//                 string remain = s_num.substr(1,10);
//                 reverse_string(remain);
//                 int compare = stoi(remain);
//                 if (compare <= max_int/10)
//                     reverse_string(s_num);
//                 else
//                     s_num = '0';
//             }
//             else
//                 s_num = '0';
//         }
//         else {
//             reverse_string(s_num);
//         }
//         x = stoi(s_num);
//         x *= sign;
//         cout << "s_num is: " << x << endl;
//         return x;
//     }
// private:
//     void reverse_string(string & s) {
//         int n = s.length();
//         for (int i = 0; i <= n/2; i++) {
//             swap(s[i], s[n - i - 1]);
//         }
//     }
// optimize way
public:
    int reverse(int x) {
        int res = 0;
        int max_int = INT_MAX;
        int min_int = INT_MIN;
        
        while (x) {
            if (res > INT_MAX/10 || res < INT_MIN/10)
                return 0;
            res = res*10 + x%10;
            x = x/10;
        }
        return res;
    }

    int reverse(int x) {
        int output = 0;
        while(x != 0)
        {
            if (output > INT_MAX/10 || output < INT_MIN/10)
                return 0;
            output = x % 10 + output*10;
            x = x / 10;
        }
        return output;
    }
};


int main() {
    // int num = -123;
    // int num = 4294967295;
    // int num = 3927694924;
    int num = 1463847412;
    Solution obj;
    int output = obj.reverse(num);

    cout << "output is: " << output << endl;

    return 0;
}