#ifndef VECMATH_H
#define VECMATH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct vecmath_matrix4 vecmath_matrix4_t;

typedef struct vecmath_vector3_t {
    float x;
    float y;
    float z;
} vecmath_vector3;

vecmath_matrix4_t *vecmath_matrix4_create();
void vecmath_matrix4_identity(vecmath_matrix4_t *matrix);
void vecmath_matrix4_multiply(vecmath_matrix4_t *m1, vecmath_matrix4_t *m2);
void vecmath_matrix4_make_translation(vecmath_matrix4_t *m, float x, float y, float z);
void vecmath_matrix4_destroy(vecmath_matrix4_t *matrix);
const float* vecmath_matrix4_data(const vecmath_matrix4_t*);

vecmath_vector3_t vecmath_vector3_add(vecmath_vector3_t v1, vecmath_vector3_t v2);
vecmath_vector3_t vecmath_vector3_sub(vecmath_vector3_t v1, vecmath_vector3_t v2);
vecmath_vector3_t vecmath_vector3_applyMatrix4(vecmath_vector3_t v1, const vecmath_matrix4_t* m);

#ifdef __cplusplus
}
#endif
#endif //VECMATH_H
