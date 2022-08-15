#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void foo()
{
    std::cout << "empty foo" << std::endl;
}

void foo( int a, int b )
{
    std::cout << "a: " << a << " b: " << b << std::endl;
}

void foo( int a, double b, char c )
{
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
}

void boo( int a, double b = 1.0, char c = 'c' )
{
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
}

PYBIND11_MODULE( Overloading, module )
{
    module.def( "foo", py::overload_cast<>( &foo ), "foo" );
    module.def( "foo", py::overload_cast< int, int >( &foo ), "foo" );
    module.def( "foo", py::overload_cast< int, double, char >( &foo ), "foo" );
    module.def( "boo", &boo, "foo", 
        py::arg( "a" ),
        py::arg( "b" ) = 1.0,
        py::arg( "c" ) = 'c' );
}

