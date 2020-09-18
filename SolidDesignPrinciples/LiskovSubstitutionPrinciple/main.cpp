#include <iostream>

using namespace std;

class Rectangle {
protected: 
	int width, height;

public:
	Rectangle(int _width, int _height) : width(_width), height(_height) {}

	virtual void setWidth(int _width) {
		width = _width;
	}

	int getWidth() {
		return width;
	}

	virtual void setHeight(int _height) {
		height = _height;
	}

	int getHeight() {
		return height;
	}

	int area() const { 
		return width * height;
	}
};

class Square : public Rectangle {

public:
	Square(int _size) : Rectangle(_size,_size) {}

	void setWidth(int _width) override {
		width = _width;
		height = width;
	}

	void setHeight(int _height) override {
		width = _height;
		height = _height;
	}
};


void process(Rectangle& _r) {
	int w = _r.getWidth();
	_r.setHeight(10);

	cout << "expected area = " << (w*10) << ", got " << _r.area() << endl;
}

struct RectanlgeFactory {
	static Rectangle create_rectangle(int _w, int _h);
	static Rectangle create_square(int _size);
};

int main() {

	Rectangle r{3,4};
	process(r);

	Square s{5};
	process(s);  // This breaks LSP because a the derived class, Square cannot be
	             // used in a function designed for it's base class, Rectangle. 

	return 0;
}