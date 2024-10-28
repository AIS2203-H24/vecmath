#ifndef VECMATH_H
#define VECMATH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct vecmath_matrix vecmath_matrix_t;

typedef struct vecmath_vector3_t {
    float x;
    float y;
    float z;
} vecmath_vector3;

vecmath_matrix_t *vecmath_matrix_create();
void vecmath_matrix_identity(vecmath_matrix_t *matrix);
void vecmath_matrix_multiply(vecmath_matrix_t *m1, vecmath_matrix_t *m2);
void vecmath_matrix_make_translation(vecmath_matrix_t *m, float x, float y, float z);
void vecmath_matrix_destroy(vecmath_matrix_t *matrix);
const float* vecmath_matrix_data(vecmath_matrix_t*);

vecmath_vector3_t vecmath_vector3_add(vecmath_vector3_t v1, vecmath_vector3_t v2);

#ifdef __cplusplus
}
#endif
#endif //VECMATH_H
