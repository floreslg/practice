#include<assert.h>
#include<cstdint>
using namespace std;


class Rectangle
{ 
public:
    Rectangle(const uint32_t width, const uint32_t height);

    uint32_t getWidth() const;
    uint32_t getHeight() const;

    virtual void setWidth(const uint32_t width);
    virtual void setHeight(const uint32_t height);

    uint32_t area() const;

protected:
    uint32_t _width;
    uint32_t _height;
};


class Square : public Rectangle
{
public:
    Square(uint32_t size);
    
    void setWidth(const uint32_t width) override;
    void setHeight(const uint32_t height) override;
};


/* process metho violate LSP because setHeight alter the comportment
   of the subtype Square. setHeight is not substituable. */
int process(Rectangle& rectangle)
{
    uint32_t wRec = rectangle.getWidth();
    rectangle.setHeight(10);

    return wRec * 10;
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
uint32_t Rectangle::area() const {return _width * _height;}


Square::Square(uint32_t size) : Rectangle(size, size) {};
void Square::setWidth(const uint32_t width) {_width = _height = width;}
void Square::setHeight(const uint32_t height) {_height = _width = height;}