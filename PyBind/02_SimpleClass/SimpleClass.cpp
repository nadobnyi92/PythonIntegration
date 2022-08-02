#include <pybind11/pybind11.h>

using namespace pybind11::literals;
namespace py = pybind11;

class CppObject
{
public:
    CppObject() {}
    CppObject( std::string name, int field = 0 ) : mName( name ), mIntField( field ) {}
    void setName( std::string name ) { mName = name; }
    std::string name() const { return mName; }

    int getField() const { return mIntField; }
    void setField( int val ) { mIntField = val; }

    double mDoubleField;

private:
    std::string mName;
    int mIntField;
};

PYBIND11_MODULE( SimpleClass, module )
{
    py::class_<CppObject>( module, "CppObject" )
        .def( py::init<>() )
        .def( py::init< std::string, int >(), "name"_a, "field"_a=0 )
        .def( "setName", &CppObject::setName )
        .def( "name", &CppObject::name )
        .def_readwrite( "value", &CppObject::mDoubleField )
        .def_property( "property", &CppObject::getField, &CppObject::getField );
}

