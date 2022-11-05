#include <iostream>
#include <pybind11/pytypes.h>
#include <vector>
#include <map>
#include <string>

#include <pybind11/embed.h>

namespace py = pybind11;
using namespace py::literals;

std::pair< std::string, std::string> parse_arg( const std::string& arg )
{
    size_t pos = arg.find_first_of( '=' );
    std::string key = pos != std::string::npos ? arg.substr( 0, pos ) : "";
    std::string value = pos != std::string::npos ? arg.substr( pos + 1, arg.length() ) : arg;
    return { key, value };
}

void parser_args( int argc, char** argv, py::list& args, py::dict& kwargs )
{
    for( int i = 1; i < argc; ++i )
    {
        auto arg = parse_arg( argv[i] );
        if( arg.first.empty() )
        {
            args.append( arg.second );
        }
        else
        {
            kwargs[arg.first.c_str()] = arg.second;
        }
    }
}

int main(int argc, char** argv)
{
    py::scoped_interpreter guard{};

    py::list args{};
    py::dict kwargs{};
    parser_args( argc, argv, args, kwargs );

    py::module_ sys = py::module_::import("sys");
    sys.attr( "path" ).attr("insert")(1, "/home/nadobnyi/Projects/PythonIntegration/PyBind/08_embedding/");
    py::module_ test = py::module_::import("test_module");
    test.attr("print_args")( *args, **kwargs );
    return 0;
}

