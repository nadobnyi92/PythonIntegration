#include "simple_library.h"

#include <cmath>
#include <cstdio>

double simple_method( int value )
{
    return pow( value, 2.0 );
}

void print_a( const StructA* a )
{
    printf( "int: %d\ndouble: %f\nstring: %s\n", a->field_int, a->field_double, a->fiend_string );
}
