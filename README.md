# Design Patterns
A collection of design patterns in modern C++ based on Dmitri Nesteruk Udemy 
course [Design Patterns in Modern C++](https://www.udemy.com/course/patterns-cplusplus/).

## SOLID Design Principles
- [Single Responsibility Principle](./SolidDesignPrinciples/SingleResponsibilityPrinciple/SingleResponsibility.md)
  - A class should only have one reason to change
  - *Separation of concerns* - different classes handling different, independent
    tasks/problems.
- [Open-Closed Principle](./SolidDesignPrinciples/Open-ClosedPrinciple/Open-ClosedPrinciple.md)
  - Classes should be open for extension but closed for modification.
- [Liskov Substitution Principle](./SolidDesignPrinciples/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.md)
  - You should always be able to substitutes a base type for a subtype.
- [Interface Segregation Principle](./SolidDesignPrinciples/LiskovSubstitutionPrinciple/LiskovSubstitutionPrinciple.md)
  - Don't put too much into an interface; split into separate interfaces.
  - *YAGNI* - You Ain't Going to Need It. 
- [Dependency Inversion Principle](./SolidDesignPrinciples/DependencyInversionPrinciple/InterfaceSegregationPrinciple.md)
  - High-level modules should not depend upon low-level ones; use abstractions.

## Gamma Categorization
Design Patterns are typically split into three categories. This is called 
*Gamma Categorization* after Erick Gamma, one of the GoF authors.

- Creational Patterns
  - Deal with the creation (construction) of objects
  - Explicit (constructor) vs. implicit (DI, reflection, etc.)
  - Wholesale (single statement) vs. piecewise (step-by-step)
- Structural Patterns
  - Concerned with the structure (e.g., class members)
  - Many patterns are wrappers that mimic the underlying class' interface
  - Stress the importance of good API design
- Behavioral Patterns
  - They are all different; no central theme

## References

[Design Patterns in Modern C++](https://www.udemy.com/course/patterns-cplusplus/)

[Design Patterns](https://en.wikipedia.org/wiki/Design_Patterns)

[Design Principle and Design Patterns](https://web.archive.org/web/20150906155800/http://www.objectmentor.com/resources/articles/Principles_and_Patterns.pdf)