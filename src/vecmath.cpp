#include "vecmath.h"

#include <iostream>
#include <Matrix4.hpp>
#include <Vector3.hpp>

#include <memory>

struct vecmath_matrix4
{
    vecmath::Matrix4 cppMatrix;
};

vecmath_matrix4_t* vecmath_matrix4_create()
{
    auto m = std::make_unique<vecmath_matrix4_t>();
    return m.release();
}

void vecmath_matrix4_destroy(vecmath_matrix4_t* matrix)
{
    delete matrix;
}

void vecmath_matrix4_identity(vecmath_matrix4_t* matrix)
{
    matrix->cppMatrix.identity();
}

void vecmath_matrix4_multiply(vecmath_matrix4_t* m1, vecmath_matrix4_t* m2)
{
    auto& cppm1 = m1->cppMatrix;
    auto& cppm2 = m2->cppMatrix;

    cppm1.multiply(cppm2);
}

const float* vecmath_matrix4_data(const vecmath_matrix4_t* m)
{
    return m->cppMatrix.elements.data();
}

void vecmath_matrix4_make_translation(vecmath_matrix4_t* m, float x, float y, float z)
{
    m->cppMatrix.makeTranslation(x, y, z);
}

vecmath_vector3_t vecmath_vector3_add(vecmath_vector3_t v1, vecmath_vector3_t v2)
{
    auto cppv1 = vecmath::Vector3(v1.x, v1.y, v1.z);
    auto cppv2 = vecmath::Vector3(v2.x, v2.y, v2.z);

    auto result = cppv1.add(cppv2);

    return {result.x, result.y, result.z};
}

vecmath_vector3_t vecmath_vector3_sub(vecmath_vector3_t v1, vecmath_vector3_t v2)
{
    auto cppv1 = vecmath::Vector3(v1.x, v1.y, v1.z);
    auto cppv2 = vecmath::Vector3(v2.x, v2.y, v2.z);

    auto result = cppv1.sub(cppv2);

    return {result.x, result.y, result.z};
}

vecmath_vector3_t vecmath_vector3_applyMatrix4(vecmath_vector3_t v1, const vecmath_matrix4_t* m)
{
    auto cppv1 = vecmath::Vector3(v1.x, v1.y, v1.z);
    auto result = cppv1.applyMatrix4(m->cppMatrix);

    return {result.x, result.y, result.z};
}
