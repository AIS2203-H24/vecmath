
import ctypes
from ctypes import c_void_p

dllPath = f"{__file__}/../../cmake-build-debug/src/vecmathc.dll"

handle = ctypes.CDLL(dllPath)

matrix_create = handle.vecmath_matrix_create
matrix_create.restype = c_void_p

