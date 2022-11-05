#include <string>
#include <map>
#include <vector>
#include <iostream>

#include <Python.h>

std::pair< std::string, std::string> parse_arg( const std::string& arg )
{
    size_t pos = arg.find_first_of( '=' );
    std::string key = pos != std::string::npos ? arg.substr( 0, pos ) : "";
    std::string value = pos != std::string::npos ? arg.substr( pos + 1, arg.length() ) : arg;
    return { key, value };
}

void parser_args( int argc, char** argv, std::vector< std::string >& args, std::map< std::string, std::string >& kwargs )
{
    for( int i = 1; i < argc; ++i )
    {
        auto arg = parse_arg( argv[i] );
        if( arg.first.empty() )
        {
            args.push_back( arg.second );
        }
        else
        {
            kwargs.insert( arg );
        }
    }
}

int main( int argc, char **argv )
{

    std::vector<std::string> args;
    std::map<std::string, std::string> kwargs;
    parser_args( argc, argv, args, kwargs );

    Py_Initialize();

// import syspath
    PyObject* sysPath = PySys_GetObject((char*)"path");
    PyObject* programName = PyUnicode_FromString( "/home/nadobnyi/Projects/PythonIntegration/libpython/libpython_embedding" ) ;
    PyList_Append(sysPath, programName);

    PyObject* pyModule = PyImport_Import( PyUnicode_FromString( "test_module" ) );
    PyObject* pyModuleDict = PyModule_GetDict( pyModule );
    PyObject* pyFunc = PyDict_GetItemString( pyModuleDict, "print_args" );

    PyObject *pyArgs = PyTuple_New( args.size() );
    for( int i = 0; i < args.size(); ++i )
    {
        PyTuple_SetItem( pyArgs, i, PyUnicode_FromString( args[i].c_str() ) );
    }

    PyObject* pyKwargs = PyDict_New();
    for( auto kwarg: kwargs)
    {
        PyDict_SetItem( pyKwargs, PyUnicode_FromString( kwarg.first.c_str() ),
                                  PyUnicode_FromString( kwarg.second.c_str() ) );
    }

    PyObject_Call( pyFunc, pyArgs, pyKwargs );

    PyObject* pyFuncCount = PyDict_GetItemString( pyModuleDict, "args_count" );
    PyObject* result = PyObject_Call( pyFuncCount, pyArgs, pyKwargs );
    std::cout << "args count: " << PyLong_AsLong( PyTuple_GetItem( result, 0 ) )
              << " kwargs count: " << PyLong_AsLong( PyTuple_GetItem( result, 1 ) ) << std::endl;

    Py_Finalize();
    return 0;
}