#include <iostream>
#include "player.h"


int main(){

    Player p1("Basketball","John","Snow");
    std::cout << "player : " << p1 << std::endl;

    std::string first_name = "Huynh";
    std::string last_name = "Hoang";
    Person per(first_name, last_name);
    // the protected member is not public member, it's only accessed from class member (member function)
    // per.test_set_name("Dro");
   
    return 0;
}