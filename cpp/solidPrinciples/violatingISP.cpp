#include<iostream>
using namespace std;



struct Document {string _content = "doc content";};


class IMachine
{
    virtual void print(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
};


class MultiFunctionPrinter : public IMachine
{
public:
    void print(Document& doc) override;
    void fax(Document& doc) override;
    void scan(Document& doc) override;
};


class Scanner : public IMachine
{
public:
    void print(Document& doc) override;
    void fax(Document& doc) override;
    void scan(Document& doc) override;
};


int main()
{
    Document doc;

    MultiFunctionPrinter multPrint;
    multPrint.print(doc);
    multPrint.scan(doc);
    multPrint.fax(doc);

    Scanner scanner;
    scanner.scan(doc);
    scanner.print(doc);
}

void MultiFunctionPrinter::print(Document& doc)
{
    cout << "MultiFunctionPrinter::print : " << doc._content << endl;
};

void MultiFunctionPrinter::scan(Document& doc)
{
    cout << "MultiFunctionPrinter::scan : " << doc._content << endl;
};

void MultiFunctionPrinter::fax(Document& doc)
{
    cout << "MultiFunctionPrinter::fax : " << doc._content << endl;
};


void Scanner::print(Document& doc)
{ /* blank */ };

void Scanner::fax(Document& doc)
{ /* blank */ };

void Scanner::scan(Document& doc)
{
    cout << "Scanner::scan : " << doc._content << endl;
};
