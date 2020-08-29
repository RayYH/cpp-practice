# CPP Practice

Some cpp code, **use at your own risk**. The structure of this project was inspired by [this repo](https://github.com/KanoComputing/googletest-sample).

## Requirements

In order to get things working, you will need:

+ C++ compiler (ideally C++11 compatible)
+ Make
+ CMake (> 2.8.11)

## Building

Compile with:

```bash
$ cmake .
$ make
```

Run main executable:

```bash
$ ./cpp_practice
```

Run tests:

```bash
$ ./tests/tests
```

You can build and run the tests all this with one line:

```bash
$ cmake . && make && ./tests/tests
```

## Style Guide

See [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

## License

[MIT](./LICENSE).
