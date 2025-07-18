Cpp - https://cplusplus.com/doc/oldtutorial/typecasting/


## Dynamic casting

`dynamic_cast is mainly used for safe downcasting in an inheritance hierarchy. It performs runtime type checking, and works only if the base class is polymorphic (i.e., has at least one virtual function).`

- can be used with pointers and references to objects.  

Base ptr to Derived is problematic - checks this during runtime for polymorphic base classes, if not successful, return a null pointer 
Derived ptr to base is alright.  

When a class is polymorphic, dynamic_cast performs a special checking during runtime to ensure that the expression yields a valid complete object of the requested class.  
If not successful, returns a NULL pointer.

## Static casting
If you cannot cast into the other object like say two independent classes , gives a compile time error.  

## Reinterpret casting

## Const casting
