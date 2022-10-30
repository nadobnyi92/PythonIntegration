#include <python3.9/Python.h>
#include <python3.9/structmember.h>
#include "simple_library.h"

struct PyStructA
{
    PyObject_HEAD
    StructA wrapped;
};

static PyObject* StructA_new( PyTypeObject* type, PyObject* args, PyObject* kwargs )
{
    PyStructA* self;
    self = (PyStructA*)type->tp_alloc( type, 0 );
    return (PyObject*) self;
}

PyMemberDef membersStructA[] = {
    {
        "field_int",
        T_INT,
        offsetof(PyStructA, wrapped.field_int),
        RESTRICTED,
        NULL
    },
    {
        "field_double",
        T_FLOAT,
        offsetof(PyStructA, wrapped.field_double),
        RESTRICTED,
        NULL
    }
};

static PyObject* struct_a_get_string ( PyStructA* self, void* closure )
{
    return PyBytes_FromString( self->wrapped.field_string );
}

static int struct_a_set_string ( PyStructA* self, PyObject* value, void* closure )
{
    self->wrapped.field_string = PyBytes_AsString( value );
    return 0;
}

PyGetSetDef getsets[] = {
    {
        "field_string",
        (getter) struct_a_get_string,
        (setter) struct_a_set_string,
        NULL,
        NULL
    },
    { NULL }
};

static PyTypeObject ObjStructA = {
    PyObject_HEAD_INIT(NULL)
    .tp_name = "key",
    .tp_basicsize = sizeof(PyStructA),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_members = membersStructA,
    .tp_getset = getsets,
    .tp_new = StructA_new,
};

static PyObject* py_print_a( PyObject* self, PyObject* args )
{
    PyStructA* obj = NULL;
    if( !PyArg_ParseTuple( args, "O", &obj ) )
    {
        PyErr_SetString( PyExc_ValueError, "failed parse arguments" );
        return NULL;
    }
    print_a( &( obj->wrapped ) );
    return Py_None;
}

static PyObject* py_simple_method( PyObject* self, PyObject* args )
{
    int cvalue = 0;
    if( !PyArg_ParseTuple( args, "i", &cvalue ) )
    {
        PyErr_SetString( PyExc_ValueError, "failed parse arguments" );
        return NULL;
    }
    double ret = simple_method( cvalue );
    return PyFloat_FromDouble( ret );
}

static PyMethodDef SimpleWrapper [] = {
    { "simple_method", py_simple_method, METH_VARARGS, "simple_method" },
    { "print_a", py_print_a, METH_VARARGS, "print_a" },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef py_SimpleWrapper = {
    PyModuleDef_HEAD_INIT,
    "SimpleWrapper",
    "Libpython simple example",
    -1,
    SimpleWrapper
};

PyMODINIT_FUNC PyInit_simple_wrapper(void) {
    PyObject* module = PyModule_Create(&py_SimpleWrapper);
    if( PyType_Ready( &ObjStructA ) < 0 )
    {
        return NULL;
    }
    Py_INCREF( &ObjStructA );
    PyModule_AddObject( module, "StructA", (PyObject*)&ObjStructA );
    return module;
}