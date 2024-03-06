#include <string>
#include <iostream>

using namespace std;
template<typename T>
int hunt_down(const T& collection,const T* value, size_t size) {
    int res = -1;
    for (int i = 0; i < size; i++) {
        if (collection == value[i]) {
            res = 0;
            break;
        }
    }
    return res;
}

int main()
{
    const std::string students[] {"Steve","Karly","Sally","Salim"} ;
    std::string to_find{"Steve"};
    int res = hunt_down(to_find,students,4);
    cout << "res is: " << res << endl;

    return 0;
}