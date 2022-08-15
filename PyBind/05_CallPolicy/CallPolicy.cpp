#include <pybind11/pybind11.h>

namespace py = pybind11;

struct A { int a; };
struct B { double b; };

A& foo( A* a, const B& b)
{
    a->a += b.b;
    return *a;
}

PYBIND11_MODULE( CallPolicy, module )
{
    py::class_<A>( module, "A" )
        .def( py::init<>() )
        .def_readwrite( "a", &A::a );
    py::class_<B>( module, "B" )
        .def( py::init<>() )
        .def_readwrite( "b", &B::b );
    module.def( "foo", foo , py::return_value_policy::take_ownership );
}

