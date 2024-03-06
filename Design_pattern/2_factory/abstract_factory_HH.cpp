#include <string>
#include <iostream>
#include <memory>
#include <map>

using namespace std;

class HotDrink {
public:
    virtual void prepare(int volume) = 0;
};

class Coffee final : public HotDrink {
    virtual void prepare(int volume) override {
        cout << "Grind some beans, boil water, pour " << volume << "ml, add cream, enjoy!" << endl;
    }
};

class Tea final : public HotDrink {
    virtual void prepare(int volume) override {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << endl;
    }
};

class HotDrinkFactory {
public:
    virtual unique_ptr<HotDrink> make() = 0;
};

class CoffeeFactory: public HotDrinkFactory {
    virtual unique_ptr<HotDrink> make() override {
        return make_unique<Coffee>();
    }
};

class TeaFactory: public HotDrinkFactory {
    virtual unique_ptr<HotDrink> make() override {
        return make_unique<Tea>();
    }
};

class DrinkFactory {
    map<string, unique_ptr<HotDrinkFactory>> container;
public:
    DrinkFactory() {
        container["coffee"] = make_unique<CoffeeFactory>();
        container["tea"] = make_unique<TeaFactory>();
    }
    unique_ptr<HotDrink> make_drink(string name) {
        auto drink = container[name]->make();
        if (name == "tea") {
            drink->prepare(200);
        }
        else if (name == "coffee") {
            drink->prepare(100);
        }
        return drink;
    }
};

int main()
{
    DrinkFactory df;
    unique_ptr<HotDrink> cf = df.make_drink("coffee");

    unique_ptr<HotDrink> te = df.make_drink("tea");

    return 0;
}