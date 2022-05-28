#include<iostream>
using namespace std;



struct Document {string _content = "doc content";};


class IPrinter
{
public:
    virtual void print(Document& doc) = 0;
};


class IScanner
{
public:
    virtual void scan(Document& doc) = 0;
};


class Printer : public IPrinter
{
public:
    void print(Document& doc) override;
};


class Scanner : public IScanner
{
public:
    void scan(Document& doc) override;
};


class IMachine : public IPrinter, public IScanner {};


class Machine : public IMachine
{
    IPrinter& _printer;
    IScanner& _scanner;

public:
    Machine(IPrinter& printer, IScanner& scanner);

    void print(Document& doc) override;
    void scan(Document& doc) override;
};


int main()
{
    Document doc;

    Printer printer;
    Scanner scanner;

    Machine machine(printer, scanner);
    machine.print(doc);
    machine.scan(doc);

    scanner.scan(doc);

};


void Printer::print(Document& doc)
{
    cout << "Printer::print : " << doc._content << endl;
};

void Scanner::scan(Document& doc)
{
    cout << "Scanner::scan : " << doc._content << endl;
};


Machine::Machine(IPrinter& printer, IScanner& scanner):
    _printer(printer), _scanner(scanner) {};

void Machine::print(Document& doc)
{
    _printer.print(doc);
};

void Machine::scan(Document& doc)
{
    _scanner.scan(doc);
};
