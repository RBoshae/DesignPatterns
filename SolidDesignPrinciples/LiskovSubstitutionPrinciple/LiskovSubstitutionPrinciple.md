# Liskov Substitution Principle
The Liskov Substitution principle, named after Robert Liskov, specifies that 
subtypes should be immediately substitutable for their base t

## How the Open-Closed Principle is Used in This Example
The code example [main.cpp](./main.cpp) demonstrates how the Liskov Substitution 
principle is violated by showing the Square class, which inherits from the 
Rectangle class, cannot be properly used in the process function. 

## Specification Design Pattern
A solution to this problem is to used the specification design pattern.