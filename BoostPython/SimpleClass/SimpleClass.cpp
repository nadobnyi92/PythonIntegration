#include <boost/python.hpp>

using namespace boost::python;

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

class ImplObject : public CppObject
{
};


BOOST_PYTHON_MODULE( simple_class )
{
    class_<CppObject>( "CppObject", init<>() )
        .def( init< std::string, optional< int > >() )
        .def( "setName", &CppObject::setName )
        .def( "name", &CppObject::name )
        .def_readwrite( "value", &CppObject::mDoubleField )
        .add_property( "property", &CppObject::getField, &CppObject::getField );
}

