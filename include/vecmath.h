#ifndef VECMATH_H
#define VECMATH_H

extern "C" {
typedef struct vecmath_matrix_t vecmath_matrix;

typedef struct vecmath_vector3_t {
    float x;
    float y;
    float z;
} vecmath3_vector;

vecmath_matrix_t *vecmath_matrix_create();
void vecmath_matrix_identity(vecmath_matrix *matrix);
void multiply(vecmath_matrix_t *m1, vecmath_matrix_t *m2);
void vecmath_matrix4_make_translation(vecmath_matrix_t *m, float x, float y, float z);
void vecmath_matrix_destroy(vecmath_matrix_t *matrix);

vecmath_vector3_t vecmath_vector3_create(float x, float y, float z);
vecmath_vector3_t add(vecmath_vector3_t v1, vecmath_vector3_t v2);
}
#endif //VECMATH_H
