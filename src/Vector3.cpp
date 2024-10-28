#include "Vector3.hpp"

using namespace vecmath;

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

Vector3 Vector3::add(const Vector3& other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::sub(const Vector3& other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::applyMatrix4(const Matrix4& m) const
{
    const auto x_ = this->x, y_ = this->y, z_ = this->z;
    const auto& e = m.elements;

    const auto w = 1.0f / (e[3] * x + e[7] * y + e[11] * z + e[15]);

    float _x = (e[0] * x_ + e[4] * y_ + e[8] * z_ + e[12]) * w;
    float _y = (e[1] * x_ + e[5] * y_ + e[9] * z_ + e[13]) * w;
    float _z = (e[2] * x_ + e[6] * y_ + e[10] * z_ + e[14]) * w;

    return Vector3{_x, _y, _z};
}
