# Class and object

## Rule of five

If you define any one of the following methods, you probably need all five.

```
~Class();                       // Destructor
Class(Class &)                  // Copy constructor
Class(Class &&)                 // Move constructor
Class & operator = (Class &);   // Copy assignment
Class & operator = (Class &&);  // Move assignment

