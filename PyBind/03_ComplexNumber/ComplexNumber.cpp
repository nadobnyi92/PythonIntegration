#include <sstream>
#include <iostream>

#include <pybind11/pybind11.h>

using namespace pybind11::literals;
namespace py = pybind11;

class ComplexNumber
{
public:
    ComplexNumber()
        : re( 0 ), im( 0 ) {}
    ComplexNumber( double re_, double im_)
        : re( re_ ), im( im_ ) {}

    bool operator == ( const ComplexNumber& other )
    {
        return re == other.re && im == other.im;
    }

    ComplexNumber operator + ( const ComplexNumber& other)
    {
        return { re + other.re, im + other.im };
    }

    ComplexNumber operator - ( const ComplexNumber& other)
    {
        return { re - other.re, im - other.im };
    }

    ComplexNumber operator * ( const ComplexNumber& other)
    {
        return { re * other.re - im * other.im, re * other.im + im * other.re };
    }

    ComplexNumber operator / ( const ComplexNumber& other)
    {
        double devider = pow( other.im, 2 ) + pow( other.re , 2 );
        double newIm = ( re * other.re + im * other.im ) / devider;
        double newRe = ( re * other.im - im * other.re ) / devider;
        return { newIm, newRe };
    }

    std::string to_str() const
    {
        std::stringstream ss;
        ss << re << ( im > 0 ? " + " :  " " ) << im << "i";
        return ss.str();
    }

    void print()
    {
        std::cout << to_str() << std::endl;
    }

private:
    double re;
    double im;
};

PYBIND11_MODULE( ComplexNumber, module )
{
    py::class_<ComplexNumber>( module, "ComplexNumber" )
        .def( py::init<>() )
        .def( py::init<double, double>() )
        .def( "__eq__", &ComplexNumber::operator== )
        .def( "__add__", &ComplexNumber::operator+ )
        .def( "__sub__", &ComplexNumber::operator- )
        .def( "__mul__", &ComplexNumber::operator* )
        .def( "__truediv__", &ComplexNumber::operator/ )
        .def( "__str__", &ComplexNumber::to_str )
        .def( "__repr__", &ComplexNumber::print );
}

