#include <iostream>

using namespace std;

struct Document;

struct IMachine {
	virtual void print(Document &_doc) = 0;
	virtual void scan(Document &_doc) = 0;
	virtual void fax(Document &_doc) = 0;
};

// The IMachine api is useful for our AioPrinter because the AioPrinter uses all
// of the functions specified in IMachine.
struct AioPrinter : IMachine {
	void print(Document &_doc) override {
		cout << "Print Document" << endl;
	}

	void scan(Document &_doc) override {
		cout << "Scan Document" << endl;
	}

	void fax(Document &_doc) override {
		cout << "Fax Document" << endl;
	}
};

// The IMachine api is not useful for the Scanner struct because it specifies
// too many functions.
struct Scanner : IMachine {
	void scan(Document &_doc) override {
		cout << "Scan Document" << endl;
	}

	void print(Document &_doc) override {
		cout << "Confusing feature, not part of scanner." << endl;
	}

	void fax(Document &_doc) override {
		cout << "Confusing feature, not part of scanner." << endl;
	}
};

// A better design that complies with Interface Segregation Principle
struct IPrinter {
	virtual void print(Document &_doc) = 0;
};

struct IScanner {
	virtual void scan(Document &_doc) = 0;
};

struct IFax {
	virtual void fax(Document &_doc) = 0;
};

struct Printer : IPrinter {
	void print(Document &_doc) override {
		cout << "Print Document" << endl;
	}
};

struct IPrinterScanner : IPrinter, IScanner {};

struct PrinterScanner : IPrinterScanner {

	// Make use of predefined printer and scanner.
	IPrinter& printer;
	IScanner& scanner;

	PrinterScanner(IPrinter &_printer, IScanner &_scanner) 
	: 
	printer(_printer),
	scanner(_scanner) 
	{}

	void print(Document &_doc) override {
		printer.print(_doc);
	}

	void scan(Document &_doc) override {
		scanner.scan(_doc);
	}


};

int main() {

	// Purposely left empty.
	// The important part of this topic is how the structs are implemented.

	return 0;
}