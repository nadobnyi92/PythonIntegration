#include <iostream>

#include <boost/python.hpp>

using namespace boost::python;

void hello_world()
{
    std::cout << "hello world!!!" << std::endl;
}

BOOST_PYTHON_MODULE( hello_world )
{
   def( "hello_world", hello_world );
}

