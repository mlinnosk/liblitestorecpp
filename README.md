# liblitestorecpp ![Build status](https://travis-ci.org/mlinnosk/liblitestorecpp.svg?branch=master)

C++ interface to [liblitestore](https://github.com/mlinnosk/liblitestore).

Implements C++ style interface (with RAII semantics) for **liblitestore** KV store. The API is a bit simpler to use than the C API. For reading and writing 
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
// output stream operator for Foo
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
        
        // create transaction
        auto tx = ls.createTx();
        // create two int values
        ls.create("one", 1);
        ls.create("two", 2);
        Foo f = {42, 43};
        ls.create("foo", f);

        // dump all the keys and values
        for (const auto& key : ls.keys("*"))
        {
            if (key == "foo")
            {
                // for reads the type is explicit
                const auto value = ls.read<Foo>(key);
                std::cout << key << ": " << value << "\n";
            }
            else
            {
                const auto value = ls.read<int>(key);
                std::cout << key << ": " << value << "\n";
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
cd build
cmake ..
make
```

## Tests
```sh
make test_litestorecpp
tests/test_litestorecpp
```

