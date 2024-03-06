

#include <iostream>
#include <string>

class CoolUtility {
public:
    // method
    CoolUtility() = default;
    explicit CoolUtility(const char* description) : m_object_description(description) {
        
    }
    ~CoolUtility(){};
    void what_do_you_do() {
        std::cout << m_object_description;
    }
    
    // variable
    static char* s_general_description;
private:
    const char* m_object_description;
};

char* CoolUtility::s_general_description {"Cool utility to move us all to Mars"};


int main() {
    CoolUtility cu("I can take you from point A to point #");
    cu.what_do_you_do();
    std::cout << std::endl;
    std::cout << "general purpose : " << CoolUtility::s_general_description << std::endl;
    CoolUtility::s_general_description[3] = 'b';
}


