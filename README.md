# liblitestorecpp ![Build status](https://travis-ci.org/mlinnosk/liblitestorecpp.svg?branch=master)

C++ interface to [liblitestore](https://github.com/mlinnosk/liblitestore).

Implements C++ style interface (with RAII semantics) for [liblitestore](https://github.com/mlinnosk/liblitestore) **key-value** store. The API is a bit simpler to use than the C API. For reading and writing 
template methods are provided that can be extended to user blob types by template specialization.


# Example

```cpp
#include <iostream>

#include "litestorecpp/litestorecpp.h"

struct Foo
{
    int i = 0;
    int j = 0;

    Foo() = default;
    Foo(const int i, const int j) : i(i), j(j) {}
};

std::ostream& operator<<(std::ostream& out, const Foo& f)
{
    out << "{" << i << "," << j << "}";
}


int main()
{
    try
    {
        // create the Litestore instance
        lscpp::Litestore ls("/tmp/litestore");
        
        // create transaction, not mandatory but makes
        // things faster and atomic
        auto tx = ls.createTx();
        
        // create two int values
        ls.create("one", 1);
        ls.create("two", 2);
        
        // create custom object
        ls.create("foo", Foo{42, 43});

        // dump all the keys and values
        for (const auto& key : ls.keys("*"))
        {
            std::cout << key << ": ";
            if (key == "foo")
            {
                // for reads the type is explicit
                // bacause of C++ type system
                const auto value = ls.read<Foo>(key);
                 std::cout << value << "\n";
            }
            else
            {
                const auto value = ls.read<int>(key);
                std::cout  << value << "\n";
            }
        }
    }
    catch (const std::runtime_error& ex)
    {
        std::cerr << "Exception: " << ex.what() << "\n";
    }
    return 0;
}
```

# Building
By default a shared library is built that has the **litestore** library as shared also.
## Requirements
* cmake
* C++14 compiler

```sh
git submodule init && git submodule update --recursive
mkdir build && cd build
cmake ..
make
```

## Tests
```sh
make test_litestorecpp
tests/test_litestorecpp
```

