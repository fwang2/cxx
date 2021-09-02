/*
Smart pointer:

    defined in <memory>

Unique pointer:
    * can't be copyed
    * make_unique< > only works for C++17
    * can't pass it to the function call since it requires value copy
    * but CAN pass it as a reference
    * reset() will destroy the original object, and create a new one
    * move() will transfer the ownership
    * release() will NOT destroy original object, only make the pointer null.
        
*/