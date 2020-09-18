# Open-Closed Principle
What the Open-Closed principle states your system should be open to extension,
for example by inheritance, but closed from modification.

## How the Open-Closed Principle is Used in This Example
The code example [main.cpp](./main.cpp) demonstrates the open-closed principle 
by showing how a developer tasked with implementing a filter can fall into a
trap of having to constantly modify the filter code each time they are asked to
add an addition filter.

## Specification Design Pattern
A solution to this problem is to used the specification design pattern.