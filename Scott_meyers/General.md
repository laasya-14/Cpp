## What C++ silently writes (Item 5)
- By defauly copy constructor, copy assignment, default constructor and a destructor.
- By default all these are public and inline (most member functions are inlined??)
- If a constructor is added, then default constructor won't be added by the compiler but copy constructor and assignments will be
- Does copy constructor and copy assignment on all the items in the class 
- Compiler rejects implicity copy assignmnet
    - if there are reference or const objects - compiler in this case deletes if it's not added by the programming
    - for derived classes for whose base class members copy assignment is private.

## Ins and outs of inlining
Item 30 - Scotts
 - increases the size of the object code
 - can lead to additional paging, reduced instruction cache hit rate
 - Almost all virtual calls defy inlining
    - virtual means "wait until runtime to figure out which function call"
    - inline means "replace the call site with called function"
    - thus compilers refuse since they don't know which function to replace it with
- calls through function pointers won't be inlined
- 

## Virtual, vptr, vtable and diamond problem


