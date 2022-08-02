from SimpleClass import CppObject

obj = CppObject( "test" )
print( obj.name() )
obj.setName("new Name")
print( obj.name() )

