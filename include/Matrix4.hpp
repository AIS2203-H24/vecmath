
#ifndef MATRIX4_HPP
#define MATRIX4_HPP
#include <array>

namespace vecmath {
    class Matrix4 {

    public:
        std::array<float, 16> elements{
            1.f, 0.f, 0.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f};

        Matrix4();

        // Set the elements of this matrix to the supplied row-major values n11, n12, ... n44.
        Matrix4& set(float n11, float n12, float n13, float n14, float n21, float n22, float n23, float n24, float n31, float n32, float n33, float n34, float n41, float n42, float n43, float n44);

        Matrix4& identity();

        Matrix4& multiply(const Matrix4& m);

        Matrix4& multiplyMatrices(const Matrix4& a, const Matrix4& b);

        Matrix4& makeTranslation(float x, float y, float z);

    };
}

#endif //MATRIX4_HPP
