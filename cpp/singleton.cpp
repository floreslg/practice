#include<assert.h>
#include<iostream>

class Singleton
{
    private:
    Singleton(){};
    static Singleton* instance;

    public:
    static Singleton* getInstance();

}; 


int main()
{
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();

    assert(singleton1 == singleton2);
}


Singleton* Singleton::instance = new Singleton();


Singleton* Singleton::getInstance()
{
    std::cout << instance << std::endl;
    return instance;
};