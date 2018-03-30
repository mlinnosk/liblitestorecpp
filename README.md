# liblitestorecpp
C++ interface to [liblitestore](https://github.com/mlinnosk/liblitestore).

Implements C++ style interface (with RAII semantics) for **liblitestore** KV store. The API is a bit simpler to use than the C API. For reading and writing 
template methods are provided that can be extended to user blob types by template specialization.

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

