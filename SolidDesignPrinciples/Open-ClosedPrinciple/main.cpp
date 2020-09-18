#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
	string name;
	Color color;
	Size size;
};

struct ProductFilter
{
	vector<Product*> by_color(vector<Product*> _items, Color _color) {
		vector<Product*> result;
		for (auto& i : _items) {
			if (i->color == _color) {
				result.push_back(i);
			}
		}
		return result;
	}

	vector<Product*> by_size(vector<Product*> _items, Size _size) {
		vector<Product*> result;
		for (auto& i : _items) {
			if (i->size == _size) {
				result.push_back(i);
			}
		}
		return result;
	}
};

template <typename T> struct Specification {
	virtual bool is_satisfied(T* _item) = 0;
};

template <typename T> struct Filter {
	virtual vector<T*> filter(vector<T*> _items, Specification<T>& _spec) = 0;
};

struct BetterFilter : Filter<Product> {
	vector<Product *> filter(vector<Product *> _items, Specification<Product> &_spec) 
	override {
		vector<Product*> result;
		for (auto& item : _items) {
			if (_spec.is_satisfied(item)) {
				result.push_back(item);
			}
		}
		return result;
	}
};

struct ColorSpecification : Specification<Product>
{
	Color color;
	ColorSpecification(Color _color) : color(_color) {}
	bool is_satisfied(Product *_item) override {
		return _item->color == color;
	}
};

struct SizeSpecification : Specification<Product>
{
	Size size;
	SizeSpecification(Size _size) : size(_size) {}
	bool is_satisfied(Product *_item) override {
		return _item->size == size;
	}
};


template <typename T> struct AndSpecification : Specification<T> {
	Specification<T>& first;
	Specification<T>& second;

	AndSpecification(Specification<T>& _first, Specification<T>& _second) : first(_first), second(_second) {}

	bool is_satisfied(Product* _item) override {
		return first.is_satisfied(_item) && second.is_satisfied(_item);
	}
};

int main() {
	Product apple{"Apple", Color::green, Size::small};
	Product tree{"Tree", Color::green, Size::large};
	Product house{"House", Color::blue, Size::large};

	vector<Product*> items {&apple, &tree, &house};

	// Fails open-closed principle
	cout << "Green Filter: Fails open-closed principle" << endl;
	ProductFilter pf;
	auto green_things = pf.by_color(items, Color::green);
	for (auto& item : green_things) {
		cout << item->name << " is green." << endl;
	}
	cout << endl;

	// Compies with open-closed principle
	cout << "Green Filter: Complies with open-closed principle" << endl;
	BetterFilter bf;
	ColorSpecification green(Color::green);

	for (auto& item : bf.filter(items, green)) {
		cout << item->name << " is green." << endl;
	}
	cout << endl;

	// Combinator - complies with open-closed principle
	cout << "Green and Large Filter: Complies with open-closed principle" << endl;
	SizeSpecification large(Size::large);
	AndSpecification<Product> green_and_large(green, large);

	for (auto& item : bf.filter(items, green_and_large)) {
		cout << item->name << " is green." << endl;
	}

	return 0;
}