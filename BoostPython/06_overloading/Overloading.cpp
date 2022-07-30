#include <iostream>
#include <boost/python.hpp>

using namespace boost::python;

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

BOOST_PYTHON_FUNCTION_OVERLOADS( boo_wrapper, boo, 1, 3 );

BOOST_PYTHON_MODULE( overloading )
{
    def< void() >( "foo", foo );
    def< void( int, int ) >( "foo", foo );
    def< void( int, double, char) >( "foo", foo );

    def( "boo", boo, boo_wrapper() );
}

