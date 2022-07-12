#include <iostream>

#include <boost/core/noncopyable.hpp>
#include <boost/python.hpp>

using namespace boost::python;

struct IObject
{
virtual ~IObject() = default;
virtual void f() const = 0;
};

struct IObjectWrapper : IObject, wrapper<IObject>
{
    void f() const override
    {
        this->get_override("f")();
    }
};

struct CppObject : public IObject
{
    void f() const { std::cout << "Object foo" << std::endl; }
};

IObject* create() { return new CppObject(); }

BOOST_PYTHON_MODULE( inheritance_object )
{
    class_<IObject, boost::noncopyable>( "IObjectBase", no_init )
        .def("f", &IObject::f);
    class_<IObjectWrapper, boost::noncopyable>( "IObject" )
        .def("f", pure_virtual(&IObject::f) );
    class_<CppObject, bases<IObject> >( "CppObject", init<>() )
        .def( "f", &CppObject::f );
    def("create", create,
        return_value_policy<manage_new_object>());
}

