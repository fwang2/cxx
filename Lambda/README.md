# Lambda

Lambda is available in C++11.


```
[ capture ]( param list ) -> <return_type> { 
    body; 
}
```

There are multiple ways you can capture:

* `[ var ]` capture `var` by value
* `[ var &]` capture `var` by reference
* `[=]` capture all variables by value
* `[&]` capture all variables by reference
* `[&, var]` capture all by reference, except capture `var` by value
* `[&var1, var2]` capture `var1` by reference, and `var2` by value


## Examples



