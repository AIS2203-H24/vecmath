#include "Vector3.hpp"

using namespace vecmath;

Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {
}

Vector3 Vector3::add(const Vector3 &other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::sub(const Vector3 &other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}
