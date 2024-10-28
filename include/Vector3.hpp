
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include "Matrix4.hpp"

namespace vecmath {

    class Vector3 {
    public:
        float x, y, z;

        explicit Vector3(float x = 0, float y = 0, float z = 0);

        [[nodiscard]] Vector3 add(const Vector3 &other) const;

        [[nodiscard]] Vector3 sub(const Vector3 &other) const;

        Vector3 applyMatrix4(const Matrix4 &matrix) const;
    };
}

#endif //VECTOR3_HPP
