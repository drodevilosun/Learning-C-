#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Sleep {
public:
    virtual void print() = 0;
};

class BasicSleep : public Sleep{
public:
    virtual void print() {
        cout << "This is Basic sleep \n";
    }
};

class AdvanceSleep : public Sleep {
public:
    virtual void print() {
        cout << "This is Advance sleep \n";
    }
};

class SleepFactory {
public:
    unique_ptr<Sleep> make_sleep(string sleep) {
        unique_ptr<Sleep> sleep_ptr;
        if (sleep == "basic") {
            sleep_ptr = make_unique<BasicSleep>();
        }
        else {
            sleep_ptr = make_unique<AdvanceSleep>();
        }
        return sleep_ptr;
    }
    // Sleep *make_sleep(string sleep) {
    //     Sleep *sleep_ptr;
    //     if (sleep == "basic") {
    //         sleep_ptr = new BasicSleep();
    //     }
    //     else {
    //         sleep_ptr = new AdvanceSleep();
    //     }
    //     return sleep_ptr;
    // }
};

int main() {
    SleepFactory sf;
    unique_ptr<Sleep> bs_sleep = sf.make_sleep("basic");
    bs_sleep->print();
    
    // SleepFactory sf;
    // Sleep *bs_sleep = sf.make_sleep("basic");
    // bs_sleep->print();

    return 0;
}