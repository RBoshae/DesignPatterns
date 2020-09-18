# Interface Segregation Principle
The Interface Segregation Principle suggests not to create interfaces that are
too large.

## How the Open-Closed Principle is Used in This Example
The code example [main.cpp](./main.cpp) demonstrates how the Interface 
Segregation principle is violated by defining an interface for ```IMachine```
that works for an all in one machine but doesn't make sense for a machine using 
only a subset of function.

```cpp
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
```

The Interface Segregation Principle encourages the programmer to decompose the
all-encompassing IMachine into smaller interfaces. This allows for less featured
structs, like Scanner, to take advantage of a common API without including 
useless functions.

See [main.cpp](./main.cpp) for the complete example.