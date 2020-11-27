#include <iostream>

using namespace std;

// How to compile this simple program?
// `g++ -o main main.cpp` - compile
// `g++ -std=c++11 -o main main.cpp` - use given c++ standard version
// the type of returned value of main func must be int
int main(int argc, char *argv[]) {
  string input_str;
  // argv[0] stores the executable file name
  for (int i = 1; i < argc; i++) {
    input_str += " ";
    input_str += *(argv + i);
  }

  if (!input_str.empty()) {
    cout << "CPP Practice: " << input_str << endl;
  } else {
    cout << "CPP Practice!" << endl;
  }

  // return zero means this call is successful
  // return non-zero means some error happened
  // `echo $?` get the status
  // if you `return -1`, then the `echo $?` will output 255
  return 0;
}
