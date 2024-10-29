from __future__ import annotations
import os
import ctypes
from typing import Any

from _ctypes import POINTER, Structure
from ctypes import c_void_p, c_float


def load_library():
    def suffix() -> str:
        return ".dll" if os.name == "nt" else ".so"

    def prefix() ->str:
        return "" if os.name == "nt" else "lib"

    bin_folder = f"{__file__}/../build/bin"
    return ctypes.CDLL(f"{bin_folder}/{prefix()}vecmathc{suffix()}")


handle = load_library()

matrix4_create = handle.vecmath_matrix4_create
matrix4_create.restype = c_void_p

matrix4_destroy = handle.vecmath_matrix4_destroy
matrix4_destroy.argtypes = [c_void_p]

matrix4_identity = handle.vecmath_matrix4_identity
matrix4_identity.argtypes = [c_void_p]

matrix4_multiply = handle.vecmath_matrix4_multiply
matrix4_multiply.argtypes = [c_void_p, c_void_p]

matrix4_make_translation = handle.vecmath_matrix4_make_translation
matrix4_make_translation.argtypes = [c_void_p, c_float, c_float, c_float]

matrix4_data = handle.vecmath_matrix4_data
matrix4_data.restype = POINTER(c_float)
matrix4_data.argtypes = [c_void_p]


class Matrix4:

    def __init__(self):
        self._ptr = matrix4_create()

    def identity(self):
        matrix4_identity(self._ptr)

    def multiply(self, other: Matrix4):
        matrix4_multiply(self._ptr, other._ptr)

    def make_translation(self, x: float, y: float, z: float):
        matrix4_make_translation(self._ptr, x, y, z)

    def __repr__(self):
        data = matrix4_data(self._ptr)
        return f"Matrix4({data[0]}, {data[4]}, {data[8]}, {data[12]}\n" \
               f"        {data[1]}, {data[5]}, {data[9]}, {data[13]}\n" \
               f"        {data[2]}, {data[7]}, {data[10]}, {data[14]}\n" \
               f"        {data[3]}, {data[7]}, {data[11]}, {data[15]})"

    def __del__(self):
        matrix4_destroy(self._ptr)


class Vector3(Structure):
    _fields_ = [("x", c_float), ("y", c_float), ("z", c_float)]

    def __init__(self, *args: Any, **kw: Any):
        super().__init__(*args, **kw)

    def add(self, other: Vector3) -> Vector3:
        return vector3_add(self, other)

    def sub(self, other: Vector3) -> Vector3:
        return vector3_sub(self, other)

    def apply_matrix4(self, m: Matrix4) -> Vector3:
        return vector3_applyMatrix4(self, m._ptr)

    def __repr__(self):
        return f"Vector3({self.x}, {self.y}, {self.z})"


vector3_add = handle.vecmath_vector3_add
vector3_add.restype = Vector3
vector3_add.argtypes = [Vector3, Vector3]

vector3_sub = handle.vecmath_vector3_sub
vector3_sub.restype = Vector3
vector3_sub.argtypes = [Vector3, Vector3]

vector3_applyMatrix4 = handle.vecmath_vector3_applyMatrix4
vector3_applyMatrix4.restype = Vector3
vector3_applyMatrix4.argtypes = [Vector3, c_void_p]
