from ctypes import *

class StructA( Structure ):
    _fields_=[
        ('field_int', c_int),
        ('field_double', c_double),
        ('field_string', c_char_p)
    ]

if __name__ == '__main__':
    simplelib = CDLL( './libsimple.so' )
    
    number = c_int( 10 )
    simplelib.simple_method.restype=c_double
    simplelib.simple_method.argtypes=[c_int]
    res = simplelib.simple_method( 10 )
    print( f'result: {res}' )

    a=StructA()
    a.field_int = 10
    a.field_double = 0.5
    a.field_string = c_char_p("test value".encode('UTF-8'))

    simplelib.print_a.argtypes=[ POINTER(StructA) ]
    simplelib.print_a( pointer( a ) )
