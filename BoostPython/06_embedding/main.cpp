#include <boost/python.hpp>
#include <boost/python/errors.hpp>
#include <iostream>

using namespace boost::python;

std::string parse_python_exception(){
    PyObject *type_ptr = NULL, *value_ptr = NULL, *traceback_ptr = NULL;
    PyErr_Fetch(&type_ptr, &value_ptr, &traceback_ptr);
    std::string ret("Unfetchable Python error");
    if(type_ptr != NULL)
    {
        handle<> h_type(type_ptr);
        str type_pstr(h_type);
        extract<std::string> e_type_pstr(type_pstr);
        if(e_type_pstr.check())
            ret = e_type_pstr();
        else
            ret = "Unknown exception type";
    }
    if(value_ptr != NULL)
    {
        handle<> h_val(value_ptr);
        str a(h_val);
        extract<std::string> returned(a);
        if(returned.check())
            ret +=  ": " + returned();
        else
            ret += std::string(": Unparseable Python error: ");
    }
    if(traceback_ptr != NULL)
    {
        handle<> h_tb(traceback_ptr);
        object tb(import("traceback"));
        object fmt_tb(tb.attr("format_tb"));
        object tb_list(fmt_tb(h_tb));
        object tb_str(str("\n").join(tb_list));
        extract<std::string> returned(tb_str);
        if(returned.check())
            ret += ": " + returned();
        else
            ret += std::string(": Unparseable Python traceback");
    }
    return ret;
}

int main()
{
    try
    {
        Py_Initialize();
        object sys_module = import("sys");
        sys_module.attr("path").attr("insert")(1, ".");
        object module = import("test_foo");
        object module_namespace = module.attr("__dict__");
        object foo = eval("foo( 24, 12 )", module_namespace);
        std::cout << extract<int>( foo ) << std::endl;
    }
    catch( const error_already_set& )
    {
        std::string perror_str = parse_python_exception();
        std::cout << "Error in Python: " << perror_str << std::endl;
    }
    return 0;
}

