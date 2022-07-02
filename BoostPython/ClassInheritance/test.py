from inheritance_object import CppObject, IObject, create

obj = create()
obj.f()

obj = CppObject()
obj.f()

class PyObject( IObject ):
    def f( self ):
        print("python foo")

obj = PyObject()
obj.f()

