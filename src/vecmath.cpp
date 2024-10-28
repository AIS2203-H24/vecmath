#include "vecmath.h"

#include <immintrin.h>
#include <Matrix4.hpp>
#include <memory>
#include <Vector3.hpp>

struct vecmath_matrix_t {
    vecmath::Matrix4 cppMatrix;
};

vecmath_matrix_t *vecmath_matrix_create() {
    auto m = std::unique_ptr<vecmath_matrix_t>();
    return m.release();
}


void vecmath_matrix_destroy(vecmath_matrix_t *matrix) {
    delete matrix;
}

void vecmath_matrix_identity(vecmath_matrix *matrix) {
    matrix->cppMatrix.identity();
}

void multiply(vecmath_matrix_t *m1, vecmath_matrix_t *m2) {
    auto& cppm1 = m1->cppMatrix;
    auto& cppm2 = m2->cppMatrix;

    cppm1.multiply(cppm2);
}

void vecmath_matrix4_make_translation(vecmath_matrix_t *m, float x, float y, float z) {
    m->cppMatrix.makeTranslation(x, y, z);
}

vecmath_vector3_t vecmath_vector3_create(float x, float y, float z) {
    return { x, y, z };
}

vecmath_vector3_t add(vecmath_vector3_t v1, vecmath_vector3_t v2) {
    auto cppv1 = vecmath::Vector3(v1.x, v1.y, v1.z);
    auto cppv2 = vecmath::Vector3(v2.x, v2.y, v2.z);

    auto result = cppv1.add(cppv2);

    return {result.x, result.y, result.z};


}
