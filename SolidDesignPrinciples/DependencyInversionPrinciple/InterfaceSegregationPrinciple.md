# Dependency Inversion Principle
The Dependency Inversion Principle is split into two concepts

1. High-level modules should not depend on low-level modules. Instead they 
should both depend on abstractions.

2. Abstractions should not depend on the details but rather the details should
depend on the abstraction.

In general, when talking about abstractions, we are talking about interfaces or
a base classes. 

## How the Dependency Inversion Principle is Used in This Example
The code example [main.cpp](./main.cpp) demonstrates how the Dependency 
Inversion works by defining a high-level abstract class that does not depend
on low-level concrete classes.