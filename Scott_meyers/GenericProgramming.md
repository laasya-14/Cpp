# Generic programming (Chap 7: Items 41 - 48)
## Template Specialization

templates have both type and non type parameters
```cpp
template <typename T, int n>

template <typename T>
void func<T*> // --> takes only pointer types for T
```
```cpp
template <class T>
void is(T a)
{
    cout<<"generic class"<<endl;
}

// template <typename T>
// void is<vector<T>>(vector<T> &a)
// {
//     cout<<a.size()<<endl;
// }
// can't do this for functions (only for classes) - partial template specialization

template <typename T>
void is

template <>
void is<int>(int a)
{
    cout<<"specific int"<<endl;
}


is(10);
is("hello");
```

```cpp
template <int x>
void compute()
{
    //do sth
}

template <>
void compute<0>
// ->ones that can already be devised from the parameters or already known as written below for partial template specialization
```
## Item 41
- Explicit Interfaces and Runtime polymorphism usually but templates enforce implicit interfaces and compile time polymorphism

Implicit interfaces

Compile time polymorphism

examples for implicit and explicit interfaces using templates
## Item 42
typename and class are the same like
```cpp
template <typename T>
class Hello{};
//and

template <class T>
class Hello{};
```
but typename is also used to identify nested dependent type names
Except in base class lists or as a base class identifier in a member initialization list  
//Given an example for this case
## Item 43

```cpp
template<typename Company>
class LoggingMsg: public Msg<Company>{
    public:
    ...
    void sendMsg(const Msginfo& info)
    {
        // this function send comes from base class Msg 
        send(info); // -> throws an compiler error since the compiler's scope is only the current
        this->send(info); // this works

        //can do this as well
        using Msg<Company>::send; //->tell the compiler to add this to the scope to check

        // or to explicitly mention the base class
        // but this turns off the virtual binding if the send is a virtual function and if this is overriden in this class
        Msg<Company>::send(info)
    }
}
```
## Item 44
Bloating and avoiding for templates

## Item 45
Using member function templates to accept all the compatible types
## Item 46

## Item 47
using type traits and compile time distinguishing
## Item 48
Template MetaProgramming

## CRTP
The CRTP consists in:
- inheriting from a template class,
- use the derived class itself as a template parameter of the base class.
```cpp
template <typename T>
class Base
{
    ...
};

class Derived : public Base<Derived>
{
    ...
};
```
Consider this case
```cpp
template<class T>
class Base{
    public:
    void add(){
        // this is eq to a virtual function and expect derived classes to implement it
        T &underlying = static_cast<T&>(*this);
        underlying.setvalue();

        // implement add functionality
    }

};
class Derived: public Base<Derived>{
    public:
    void setvalue(){
        // implement sth here
        cout<<"from derived 1 here"<<endl;
    }
};

// basically derived inherits base functionality and base also works on derived functionality

class Derived2: public Base<Derived2>{
    public:
    void setvalue(){
        // implement sth here
        cout<<"from derived 2 here"<<endl;
    }
};
// usage
template <class T>
void check(Base<T> &obj)
{
    obj.setvalue(); //here we want whatever T is of the type so any derived class should be able to work here
}

// usage of check in the code
int main()
{
    Base<Derived> obj1;
    Base <Derived2> obj2;
    check(obj1);
    check(obj2);
}
```

Doubts in this aspect:
1. How do we guarantee that casting from base to derived in this case is safe and doesn't lead to undefined behaviours in other cases?
2. What exactly is the usage and benefit of this polymorphism, in which cases and how do we need to use this?
## Concepts
ways to use it
```cpp

```
```cpp
class A{};
class B{
    public:
    void f(){
        cout<<" in func f"<<endl;
    }
};

template <class T>
concept Hasf = requires (T t)
{
    t.f();
};

template <class T>
requires Hasf<T>
void check(T &x)
{
    x.f();
}

template <class T>
void check(T& x)
{
    cout<<" can't do much "<<endl;
}

int main()
{
    A a;
    B b;
    check(a);
    check(b);
}
```
## Random keywords and Info:
1. An interface in C++ is:

    A class that only contains pure virtual functions (and usually no data members), which is meant to be inherited and implemented by other classes.
2. Abstract base class:
    Class that has alteast one virtual function - meaning it implemented keeping inheritance in mind.
3. `this` keyword
4. 
```cpp
class A{};
class B{
    public:
    void member_func(const B& b)
    {
        a = b.a;
        // this is legal since the access specifier checks if it's of the same class - then checks otherwise it doesn't
    }
    private:
    A a;
}
```
5. constexpr??
