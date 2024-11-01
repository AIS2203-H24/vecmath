from pyvecmath import Vector3, Matrix4

if __name__ == "__main__":
    m1 = Matrix4()
    m1.make_translation(1, 0, 5)
    m2 = Matrix4()
    m2.make_translation(1, 2, 3)

    m1.multiply(m2)
    print(m1)

    v1 = Vector3(1, 0, 0)
    v2 = Vector3(0, 1, 0)

    print(v1.add(v2))
    print(v1.apply_matrix4(m1))

    del m1
    del m2
