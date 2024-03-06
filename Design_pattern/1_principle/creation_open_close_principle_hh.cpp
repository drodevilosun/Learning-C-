#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* 
we have list of products and customer want to filter some product base on their traits
Product 
  Name
  color
  Size

The customer want to filter base on their color or size 

Open close principle: open for extension and close to modification
*/
enum class Color {
    red,
    green,
    blue
};
enum class Size {
    small,
    medium,
    large
};

class Product {
public:
    Product() = default;
    ~Product() {};
    Product(string name, Size size, Color color): mName(name), mSize(size), mColor(color) {

    }
    string mName;
    Size mSize;
    Color mColor;
};

class ProductFilter {
public:
    ProductFilter() = default;
    ~ProductFilter() {};
    typedef vector<Product *> Items;
    Items filter_color(Items items, Color color) {
        Items result;
        for (auto &pd : items) {
            if (pd->mColor == color)
                result.push_back(pd);
        }
        return result;
    }
    Items filter_size(Items items, Size size) {
        Items result;
        for (auto &pd : items) {
            if (pd->mSize == size)
                result.push_back(pd);
        }
        return result;
    }
    Items filter_color_size(Items items, Color color, Size size) {
        Items result;
        for (auto &pd : items) {
            if (pd->mSize == size && pd->mColor == color)
                result.push_back(pd);
        }
        return result;
    }
};

template<typename DataType> class AndSpecification;

template<typename DataType> class Specification {
public:
    virtual ~Specification() = default;
    // virtual bool is_satified(DataType* item) const = 0;
    virtual bool is_satified(DataType* item) const {
        cout << "Base class is called \n";
        return true;
    }
    
    AndSpecification<DataType> operator&&(DataType* other) {
        return (*this, other);
    }
};

template<typename DataType> class Filter {
public:
    virtual vector<DataType*> filter(vector<DataType*> items, Specification<DataType>& spec) = 0;
};

class BetterFilter : public Filter<Product> {
public:
    BetterFilter() = default;
    ~BetterFilter(){}
    virtual vector<Product *> filter(vector<Product*> items, Specification<Product>& spec) {
        vector<Product*> res;
        for (auto &i : items) {
            if (spec.is_satified(i))
                res.push_back(i);
        }
        return res;
    }
};

class ColorSpecification: public Specification<Product> {
public:
    ColorSpecification() = default;
    ~ColorSpecification() {}
    explicit ColorSpecification(Color color) : mColor(color) {}
    virtual bool is_satified(Product* item) const override {
        return mColor == item->mColor;
    }
private:
    Color mColor;
};

class SizeSpecification: public Specification<Product> {
public:
    SizeSpecification() = default;
    ~SizeSpecification(){}
    explicit SizeSpecification(Size size): mSize(size) {}
    virtual bool is_satified(Product *item) const override {
        return item->mSize == mSize;
    }
private:
    Size mSize;
};

template<typename DataType>
class AndSpecification : public Specification<DataType> {
public:
    const Specification<DataType> &first;
    const Specification<DataType> &second;
    
    AndSpecification(const Specification<DataType> &first, const Specification<DataType> &second) : first(first), second(second) {}
    bool is_satified(DataType* item) const override {
        return first.is_satified(item) && second.is_satified(item);
    }
};

// new
template<typename DataType>
AndSpecification<DataType> operator && (const Specification<DataType> &first, const Specification<DataType> &second) {
    return {first, second};
}

int main() {
    Product ruler("Ruler", Size::small, Color::red);
    Product table("Table", Size::medium, Color::blue);
    Product tree("Tree", Size::large, Color::green);

    vector<Product *> products {&ruler, &table, &tree};

    /* Ex 1: don't follow open close principle*/
    ProductFilter pf;
    auto red_thing = pf.filter_color(products, Color::red);
    for (auto i : red_thing) {
        cout << i->mName << " is red \n";
    }

    /* Ex2: follow open close principle */
    BetterFilter bf;
    SizeSpecification large(Size::large);
    auto l_thing = bf.filter(products, large);

    for (auto i : l_thing) {
        cout << i->mName << " is large\n";
    }
    ColorSpecification green(Color::green);

    AndSpecification<Product> green_large_thing(green, large);
    auto spec = bf.filter(products, green_large_thing);
    for (auto i : spec) {
        cout << i->mName << " is large";
    }
    // AndSpecification<Product> spec = green && large;
    // for (auto i : bf.filter(products, spec)) {
    //     cout << i->mName << " is green and large\n";
    // }

    AndSpecification spec2 = SizeSpecification(Size::large) && ColorSpecification(Color::green);

    return 0;
}