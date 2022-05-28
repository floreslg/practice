#include<assert.h>
#include<iostream>
#include<vector>
using namespace std;


enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};
struct Product {string name; Color color; Size size;};
using Items = vector<Product*>;


class ProductFilter
{
public:
    static Items byColor(const Items items, const Color color);
    static Items bySize(const Items items, const Size size);
    static Items bySizeAndColor(const Items items, const Size size, const Color color);
};


int main()
{
    Product* prod1 = new Product{"Apple", Color::Red, Size::Small};
    Product* prod2 = new Product{"Tree", Color::Red, Size::Large};
    Product* prod3 = new Product{"House", Color::Blue, Size::Large};

    const Items items = {prod1, prod2, prod3};

    const Items expByRed = {prod1, prod2};
    const Items expByLarge = {prod2, prod3};
    const Items expByRedAndLarge = {prod2};

    assert(ProductFilter::byColor(items, Color::Red) == expByRed);
    assert(ProductFilter::bySize(items, Size::Large) == expByLarge);
    assert(ProductFilter::bySizeAndColor(items, Size::Large, Color::Red) == expByRedAndLarge);
};


Items ProductFilter::byColor(const Items items, const Color color)
{
    Items filteredItems;
    for (Product* item : items)
    {
        if (item->color == color) {filteredItems.push_back(item);}
    }
    return filteredItems;
}


Items ProductFilter::bySize(const Items items, const Size size)
{
    Items filteredItems;
    for (Product* item : items)
    {
        if (item->size == size) {filteredItems.push_back(item);}
    }
    return filteredItems;
}


Items ProductFilter::bySizeAndColor(const Items items, const Size size, const Color color)
{
    Items filteredItems;
    for (Product* item : items)
    {
        if (item->color == color && item->size == size) {filteredItems.push_back(item);}
    }
    return filteredItems;
}