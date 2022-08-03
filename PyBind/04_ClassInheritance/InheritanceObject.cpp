#include <iostream>

#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>

using namespace pybind11::literals;
namespace py = pybind11;


struct IObject
{
virtual ~IObject() = default;
virtual void f() const = 0;
};

struct CppObject : public IObject
{
    void f() const { std::cout << "Object foo" << std::endl; }
};

struct PyIObject : public IObject
{
    using IObject::IObject;
    void f() const override
    {
        PYBIND11_OVERRIDE_PURE(void, IObject, f);
    }
};

IObject* create() { return new CppObject(); }

PYBIND11_MODULE(InheritanceObject, module)
{
    py::class_<IObject>( module, "IObjectBase" )
        .def("f", &IObject::f);
    py::class_<PyIObject, IObject>( module, "IObject" )
        .def( py::init<>() )
        .def("f", &IObject::f);
    py::class_<CppObject, IObject >( module, "CppObject" )
        .def( py::init<>() )
        .def( "f", &CppObject::f );
    module.def("create", create, py::return_value_policy::take_ownership );
}

