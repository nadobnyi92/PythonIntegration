from ExceptionHandling import *

try:
    foo()
except RuntimeError as e:
    print( e )

try:
    boo()
except PyException as e:
    print( e )