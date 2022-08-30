#include <exception>

#include <pybind11/pybind11.h>

namespace py = pybind11;

void foo()
{
    throw std::logic_error( "my exception" );
}

struct CppException
{
    const char* what() const noexcept { return "CppException"; }
};

void boo()
{
    throw CppException {};
}

PYBIND11_MODULE( ExceptionHandling, module )
{
    module.def( "foo", &foo, "throw logic error" );
    module.def( "boo", &boo, "throw custom exception" );

    py::register_exception<CppException>( module, "PyException");
}
