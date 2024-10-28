//
// Created by larsi on 28.10.2024.
//

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace vecmath {
    class Vector3 {
    public:
        float x, y, z;

        Vector3(float x = 0, float y = 0, float z = 0);

        Vector3 add(const Vector3 &other) const;

        Vector3 sub(const Vector3 &other) const;
    };
}

#endif //VECTOR3_HPP
