#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    unordered_map<int, string> un_data;
    un_data.insert({1, "Hoang"});
    un_data[2] = "Bi";
    un_data[3] = "Anh";

    for (auto &[first, second] : un_data) {
        second = "Hehe";
        cout << first << " " << second << std::endl;
    }

    return 0;
}