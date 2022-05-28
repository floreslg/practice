#include<assert.h>
#include<iostream>
#include<vector>
using namespace std;


enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};
struct Product {string name; Color color; Size size;};
using Items = vector<Product*>;


template <typename SpecType>
class BaseSpecification
{
public:
    virtual bool isSatisfied(Product* item) const =0;
    virtual ~BaseSpecification() = default;
};


class ColorSpecification : public BaseSpecification<Product>
{
public:
    Color byColor;

    ColorSpecification(Color color);
    bool isSatisfied(Product* item) const;
};


class SizeSpecification : public BaseSpecification<Product>
{
public:
    
    Size bySize;

    SizeSpecification(Size size);
    bool isSatisfied(Product* item) const;
};


template <typename ItemType>
class AndSpecification : public BaseSpecification<ItemType>
{
public:
    const BaseSpecification<ItemType>& firstSpec; 
    const BaseSpecification<Product>& secondSpec;

    AndSpecification(
        const BaseSpecification<ItemType>& first, 
        const BaseSpecification<ItemType>& second
    );

    bool isSatisfied(ItemType* item) const;
};


template <typename ItemType>
AndSpecification<ItemType> operator&& (
    const BaseSpecification<ItemType>& first,
    const BaseSpecification<ItemType>& second
);



template <typename ItemType>
class BaseFilter
{
public:
    virtual vector<ItemType*> filter(
        vector<ItemType*> items,
        const BaseSpecification<ItemType> &spec
    ) = 0;

};


class ProductFilter : public BaseFilter<Product>
{
public:
    vector<Product*> filter(
        vector<Product*> items,
        const BaseSpecification<Product> &spec
    );
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


    ProductFilter pf;
    ColorSpecification redColorSpec(Color::Red);
    SizeSpecification largeSizeSpec(Size::Large);

    assert(pf.filter(items, redColorSpec) == expByRed);
    assert(pf.filter(items, largeSizeSpec) == expByLarge);
    assert(pf.filter(items, redColorSpec && largeSizeSpec) == expByRedAndLarge);
};



ColorSpecification::ColorSpecification(Color color) {byColor = color;}
bool ColorSpecification::isSatisfied(Product* item) const {return item->color == byColor;}

SizeSpecification::SizeSpecification(Size size) {bySize = size;}
bool SizeSpecification::isSatisfied(Product* item) const {return item->size == bySize;}



template <typename ItemType>
AndSpecification<ItemType>::AndSpecification(
    const BaseSpecification<ItemType>& first, 
    const BaseSpecification<ItemType>& second)
: firstSpec(first), secondSpec(second) {}

template <typename ItemType>
bool AndSpecification<ItemType>::isSatisfied(ItemType* item) const
{return firstSpec.isSatisfied(item) && secondSpec.isSatisfied(item);}


template <typename ItemType>
AndSpecification<ItemType> operator&& (
    const BaseSpecification<ItemType>& first, 
    const BaseSpecification<ItemType>& second
) {return {first, second};}



vector<Product*> ProductFilter::filter(vector<Product*> items,
                                       const BaseSpecification<Product> &spec)
{
    vector<Product *> filteredItems;
    for (auto& item: items)
    {
        if (spec.isSatisfied(item)) {filteredItems.push_back(item);}
    }
    return filteredItems;
}