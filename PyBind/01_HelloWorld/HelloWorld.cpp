#include <iostream>

#include <pybind11/pybind11.h>

void hello_world()
{
    std::cout << "hello world!!!" << std::endl;
}

PYBIND11_MODULE( HelloWorld, module )
{
    module.def( "hello_world", &hello_world, "hello world" );
}

