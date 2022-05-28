#include<assert.h>
#include<cstdint>
using namespace std;


class Shape
{
public:
    virtual uint32_t area() const =0;
};


class Rectangle: public Shape
{ 
public:
    Rectangle(const uint32_t width, const uint32_t height);

    uint32_t getWidth() const;
    uint32_t getHeight() const;

    virtual void setWidth(const uint32_t width);
    virtual void setHeight(const uint32_t height);

    uint32_t area() const override;

private:
    uint32_t _width;
    uint32_t _height;
};


class Square : public Shape
{
public:
    Square(uint32_t size);
    
    void setSize(const uint32_t width);
    uint32_t area() const override;

private:
    uint32_t _size;
};


/*Current implementation avoid to use setHeight in Square shape. */
uint32_t process(Shape& shape)
{
    return shape.area();
}


int main()
{
    Rectangle rectangle(5, 5);
    assert(process(rectangle) == rectangle.area());

    Square square(5);
    assert(process(square) == square.area());
};


Rectangle::Rectangle(const uint32_t width, const uint32_t height) :
    _width(width), _height(height) {}
uint32_t Rectangle::getWidth() const {return _width;}
uint32_t Rectangle::getHeight() const {return _height;}
void Rectangle::setWidth(const uint32_t width) {_width = width;}
void Rectangle::setHeight(const uint32_t height) {_height = height;}
uint32_t Rectangle::area() const {return (_width * _height);}


Square::Square(uint32_t size) : _size(size) {};
void Square::setSize(const uint32_t size) {_size = size;}
uint32_t Square::area() const {return (_size * _size);}
