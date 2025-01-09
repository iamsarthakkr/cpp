#include<iostream>

#include "Foo.hpp"
#include "Adder.hpp"

int32_t main() {
   Foo::print();

   float a = 1.0f, b = 2.0f;
   Adder adder;
   std::cout << adder.add(a, b) << std::endl;
}

