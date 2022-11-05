def print_args( *args, **kwargs ):
    print('args:')
    for arg in args:
        print( arg )
    print('kwargs:')
    for key, value in kwargs.items():
        print( f'{key}: {value}' )

def args_count( *args, **kwargs ):
    return len( args ), len( kwargs )

if __name__ == '__main__':
    pass