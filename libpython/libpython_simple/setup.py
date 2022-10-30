from distutils.core import setup, Extension
import os

if __name__ == "__main__":
    os.environ['DISTUTILS_DEBUG'] = "1"
    
    module = Extension("simple_wrapper",
                       library_dirs=['.'],
                       runtime_library_dirs=['.'],
                       libraries=['simple'],
                       sources = ["simple_wrapper.cpp"],
                       )
    setup(name="simmple_module",
          version="1.0.0",
          description="Python interface for the fputs C library function",
          ext_modules=[module],
          options={'install_lib': {'install_dir': '.'} }
          )