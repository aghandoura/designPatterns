//Interface segregation principle

// No client should be forced to depend on methods it does not use

// PrintingMachine is made here dependent on methods that it does not need
// to solve this segregation is made between methods and if multiple interfaces are needed
// Decorator pattern is used for implementation.


#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

struct Documents;

#if 0 //violates Interface segregation principle
struct IMachine
{
	virtual void scan(std::vector<Documents*> docs) = 0;
	virtual void print(std::vector<Documents*> docs) = 0;
	virtual void fax(std::vector<Documents*> docs) = 0;
};

struct PrintingMachine : public IMachine
{
	void scan(std::vector<Documents*> docs) override;
	void print(std::vector<Documents*> docs) override;
	void fax(std::vector<Documents*> docs) override;
};
#else

struct IPrinter
{
	virtual void print(std::vector<Documents*> docs) = 0;
};

struct IScanner
{
	virtual void scan(std::vector<Documents*> docs) = 0;
};

struct IFaxer
{
	virtual void fax(std::vector<Documents*> docs) = 0;
};

class Printer : public IPrinter
{
public:
	void print(std::vector<Documents*> docs) override;
};

class Scanner : public IScanner
{
public:
	void scan(std::vector<Documents*> docs) override;
};

class Faxer : public IFaxer
{
public:
	void fax(std::vector<Documents*> docs) override;
};

struct IMachine : IPrinter, IScanner{};


class Machine : public IMachine
{
public:
	Printer& printer;
	Scanner& scanner;

	Machine(Printer& printer, Scanner& scanner)
		: printer(printer),
		  scanner(scanner)
	{
	}


	void print(std::vector<Documents*> docs) override
	{
		printer.print(docs);
	}
	void scan(std::vector<Documents*> docs) override
	{
		scanner.scan(docs);
	}
};


#endif

int _tmain(int argc, _TCHAR* argv[])
{
	
	getchar();
	return 0;
}