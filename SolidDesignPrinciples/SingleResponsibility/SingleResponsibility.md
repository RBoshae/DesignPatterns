# Single Responsibility Principle
What the single responsibility principle states is that a class should have a 
primary responsiblity and not take on extra responsibilities.

## How the Single Responsibility Principle is Used in This Example
In the code example [main.cpp](./main.cpp) a journal struct is used to convey
the single responsibility principle. The journal struct's sole responsibility 
is to model a typical journal which has a title and a collection of entries.

Where the struct begins to drift from the responsibility of a journal is when
the progammer wishes to persist/save the journal on disk. It is tempting to
write a function in the journal struct that will accomplish this task but
this can cause complications if the way the journal is saved changes. A solution
here is to seperate the responsibility of saving the journal to a different 
struct called PersistanceManager.