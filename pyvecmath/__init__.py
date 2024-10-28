from __future__ import annotations
import ctypes
from typing import Any

from _ctypes import POINTER, Structure
from ctypes import c_void_p, c_float


dllPath = f"{__file__}/../../cmake-build-debug/src/vecmathc.dll"

handle = ctypes.CDLL(dllPath)


matrix_create = handle.vecmath_matrix_create
matrix_create.restype = c_void_p

matrix_destroy = handle.vecmath_matrix_destroy
matrix_destroy.argtypes = [c_void_p]

matrix_identity = handle.vecmath_matrix_identity
matrix_identity.argtypes = [c_void_p]

matrix_multiply = handle.vecmath_matrix_multiply
matrix_multiply.argtypes = [c_void_p, c_void_p]

matrix_make_translation = handle.vecmath_matrix_make_translation
matrix_make_translation.argtypes = [c_void_p, c_float, c_float, c_float]

matrix_data = handle.vecmath_matrix_data
matrix_data.restype = POINTER(c_float)
matrix_data.argtypes = [c_void_p]


class Matrix4:

    def __init__(self):
        self._ptr = matrix_create()

    def identity(self):
        matrix_identity(self._ptr)

    def multiply(self, other: Matrix4):
        matrix_multiply(self._ptr, other._ptr)

    def make_translation(self, x: float, y: float, z: float):
        matrix_make_translation(self._ptr, x, y, z)

    def __repr__(self):
        data = matrix_data(self._ptr)
        return f"Matrix4({data[0]}, {data[4]}, {data[8]}, {data[12]}\n" \
               f"        {data[1]}, {data[5]}, {data[9]}, {data[13]}\n" \
               f"        {data[2]}, {data[7]}, {data[10]}, {data[14]}\n" \
               f"        {data[3]}, {data[7]}, {data[11]}, {data[15]})"

    def __del__(self):
        matrix_destroy(self._ptr)

class Vector3(Structure):

    _fields_ = [("x", c_float), ("y", c_float), ("z", c_float)]

    def __init__(self, *args: Any, **kw: Any):
        super().__init__(*args, **kw)

    def add(self, other) -> Vector3:
        return vector3_add(self, other)

    def __repr__(self):
        return f"Vector3({self.x}, {self.y}, {self.z})"


vector3_add = handle.vecmath_vector3_add
vector3_add.restype = Vector3
vector3_add.argtypes = [Vector3, Vector3]

