# Move Semantics

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->


## lvalue and rvalue

``` a = b; ```
* lvalue **can** appear on the left side (meaning, lvalue can also appear on the right side)

* rvalue **can only** appear on the right side of the assignment.


## Examples:

* [rational-02.cpp](rational-02.cpp), demonstrate how to write move ctor, and when it is getting called.
* [rational-03.cpp](rational-03.cpp), demonstrate move assignment.
* 