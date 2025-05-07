#include <iostream>
#include "ap_fixed.h"

// �ϥ� INT16 �w�I�� (8-bit ��Ƴ��� + 8-bit �p�Ƴ���)
typedef ap_fixed<16,8> fixed_point_t;

// ���հѼ�
#define TEST_IN_SIZE 4   // ���տ�J�j�p
#define TEST_OUT_SIZE 3  // ���տ�X�j�p

// �ŧi Linear ���
void linear(
    ap_uint<16> in_size, ap_uint<16> out_size,
    fixed_point_t feature_in[], fixed_point_t weight[], fixed_point_t feature_out[]
);

int main() {
    // �]�w��J�S�x�V�q
    fixed_point_t feature_in[TEST_IN_SIZE] = {1.0, 2.0, 3.0, 4.0};

    // �]�w�v���x�} (out_size x in_size)
    fixed_point_t weight[TEST_OUT_SIZE * TEST_IN_SIZE] = {
        1.0, 0.5, 0.0, -0.5,
        -0.5, 1.0, 0.5, 0.0,
        0.0, -0.5, 1.0, 0.5
    };

    // ��X�V�q
    fixed_point_t feature_out[TEST_OUT_SIZE];

    // ���� Linear
    linear(TEST_IN_SIZE, TEST_OUT_SIZE, feature_in, weight, feature_out);

    // ��X���G
    std::cout << "Linear Output (No Bias):\n";
    for (int i = 0; i < TEST_OUT_SIZE; i++) {
        std::cout << feature_out[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
