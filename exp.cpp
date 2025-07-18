#include <iostream>
#include <vector>
using namespace std;

class A{};
class C{};
class All_private{};
class B{
    B(const B& b){
        this->priv = b.priv;
        // can't do - b.priv.a here
    };
    int check(const B& b)
    {
        
    }
    private:
    class All_private{
        A a;
        C c;
        A getvalA(const All_private& x)
        {
            return x.a;
        }
    };
    All_private priv;
};
// objects of a particular class, when used in that class can access the private members

template<class T>
class Base{
    public:
    void setvalue(){
        // this is eq to a virtual function and expect derived classes to implement it
        T &underlying = static_cast<T&>(*this);
        underlying.setvalue();
    }

};
class Derived: public Base<Derived>{
    public:
    void setvalue(){
        // implement sth here
        cout<<"from derived 1 here"<<endl;
    }
};

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
    Derived obj1;
    Base <Derived2> obj2;
    check(obj1);
    check(obj2);
}

template<typename T>
class Shape{
    public:
    int area(){
        T &underlying = static_cast<T&>(*this);
        return underlying->area();
    }
};

class Circle: public Shape<Circle>{
    public:
    int radius;
    Circle(int r): radius(r){};
    int area()
    {
        return 3*radius*radius;
       
    }
};

template <typename T>
int get_total_area(Shape<T> &shape)
{
    return shape.area();
}

// get_total

// Shape *shape = new Circle(1);
// shape->area()