#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

// Dependency Inversion Principle
// A. High-level modules should not depend on low-level modules. Both should
//    depend on abstractions.
// B. Abstractions should not depend on details. Details should depend on 
//    abstractions.

enum class Relationship {
	parent,
	child,
	sibling
};

struct Person {
	string name;
};

// A solution the Dependency Inversion Principle.
struct RelationshipBrowser {  // high-level module
	virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser {  // low-level module
	vector<tuple <Person, Relationship, Person> > relations;

	void add_parent_and_child(const Person& _parent, const Person& _child) {
		relations.push_back({_parent,Relationship::parent, _child});
		relations.push_back({_child, Relationship::child, _parent});
	}

	vector<Person> find_all_children_of(const string& _name) override {
		vector<Person> result;
		for (auto&& [first, rel, second] : relations) {
			if (first.name == _name && rel == Relationship::parent) {
				result.push_back(second);
			}
		}

		return result;
	}
};

// Violates Dependency Inversion Principle because it has a dependency on
// Relationships, which is a low-level construct. If the implementation of 
// Relationships changes it would break the Research struct.
// A solution to this problem is to create an abstraction. The abstraction 
// created in example is called RelationShipBrowser.
// struct Research { // high-level module
// 	Research(Relationships& _relationships) {
// 		auto& relations = _relationships.relations;
// 		for (auto&& [first, rel, second] : relations) {
// 			if (first.name == "John" && rel == Relationship::parent) {
// 				cout << "John has a child called " << second.name << endl;
// 			}
// 		}
// 	}
// };

struct Research {  // high level
	Research(RelationshipBrowser& browser) {
		for (auto& child : browser.find_all_children_of("John")) {
			cout << "John has a child called " << child.name << endl;
		}
	}
};

int main() {

	Person parent{"John"};
	Person child1{"Chris"};
	Person child2{"Jen"};

	Relationships relationships;
	relationships.add_parent_and_child(parent, child1);
	relationships.add_parent_and_child(parent, child2);

	Research _(relationships);

	return 0;
}