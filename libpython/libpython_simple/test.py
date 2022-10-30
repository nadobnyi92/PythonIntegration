import simple_wrapper

if __name__ == '__main__':
    res = simple_wrapper.simple_method( 10 )
    print( f"res {res}" )

    # res = simple_wrapper.simple_method( "error" )

    a = simple_wrapper.StructA()
    a.field_int = 10
    a.field_double = 20.0
    a.field_string = "test".encode('UTF-8')
    simple_wrapper.print_a( a )