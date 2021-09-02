/*
 demo how derived class overload method in base class
 and this provide a fix in overload-v1.cpp class, where derived method is not being called
 properly.

 The fix: add "virtual" qualiifer to the speak().
 Caveat: whenever you have virtual method; define destructor.

 base class Animal, derived class Dog and Cat

 in this case, we overload "speak" method defined in base class from Cat.


*/
#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal
{
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal() {}

  protected:
    // protected constructor for use by derived classes
    //                      NOTE:
    // if we make this constructor private, then even derived class don't have access to it
    // anymore. In rare cases, we can make exceptions by making a class (either derived, or non-derived)
    // a friend, for example:

    // friend class Dog;
    // friend class Cat;
    //
    //
    // This will open up the private members to the class again.
    //
    Animal(const string &n, const string &t, const string &s) : _name(n), _type(t), _sound(s) {}

  public:
    virtual void speak() const;
    const string &name() const
    {
        return _name;
    }
    const string &type() const
    {
        return _type;
    }
    const string &sound() const
    {
        return _sound;
    }
    virtual ~Animal() {}
};

void Animal::speak() const
{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
};

// Dog class - derived from Animal
class Dog : public Animal
{
    int _walked;

  public:
    Dog(string n) : Animal(n, "dog", "woof"), _walked(0){};
    int walk()
    {
        return ++_walked;
    }
};

// Cat class - derived from Animal
// Notes:
// Cat can't access private Animal member, such as _name, _type etc.
// Cat does have access to both protected and public members, such as
// name(), type() etc.

class Cat : public Animal
{
    int _petted;

  public:
    Cat(string n) : Animal(n, "cat", "meow"), _petted(0){};
    int pet()
    {
        return ++_petted;
    }

    // NOTE: overload base class methods
    void speak() const
    {
        Animal::speak();
        puts("puurrrrr");
    }
};

int main()
{
    Dog d("Rover");
    Cat c("Fluffy");

    d.speak();

    // here, the speak() method comes from Cat.
    c.speak();

    cout << "the " << d.type() << " has been walked " << d.walk() << " times" << endl;
    cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;

    // define array of Animal pointers
    // here, notice that speak() come from base!!
    // even though we are giving it a cat pointer

    Animal *ap[] = {&d, &c};
    for(auto p : ap)
    {
        p->speak();
    }
}