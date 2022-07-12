#include <boost/python.hpp>
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/with_custodian_and_ward.hpp>

using namespace boost::python;

struct A { int a; };
struct B { double b; };

A& foo( A* a, const B& b)
{
    a->a += b.b;
    return *a;
}

BOOST_PYTHON_MODULE( call_policy )
{
    class_<A>( "A" ).def_readwrite( "a", &A::a );
    class_<B>( "B" ).def_readwrite( "b", &B::b );
    def( "foo", foo ,
            return_internal_reference< 1, with_custodian_and_ward< 1, 2 > >() );
}

