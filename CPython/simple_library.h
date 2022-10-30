#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

double simple_method( int value );

struct StructA
{
    int field_int;
    double field_double;
    char* fiend_string;
};

void print_a( const StructA* a );

#ifdef __cplusplus
} //extern "C"
#endif
