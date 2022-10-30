#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

double simple_method( int value );

typedef struct
{
    int field_int;
    double field_double;
    char* field_string;
} StructA;

void print_a( const StructA* a );

#ifdef __cplusplus
} //extern "C"
#endif
