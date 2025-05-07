#include <iostream>
#include "ap_fixed.h"

// �ϥ� INT16 �w�I�� (8-bit ��Ƴ��� + 8-bit �p�Ƴ���)
typedef ap_fixed<16,8> fixed_point_t;

// ���հѼ�
#define TEST_SIZE 5   // ���տ�J�j�p

// �ŧi BatchNorm1d ���
void batch_norm1d(
    ap_uint<16> in_size,
    fixed_point_t feature_in[], fixed_point_t scale[], fixed_point_t bias[], fixed_point_t feature_out[]
);

int main() {
    // �]�w��J�V�q
    fixed_point_t feature_in[TEST_SIZE] = {1.0, -1.0, 2.0, -2.0, 0.0};

    // �]�w BatchNorm �Ѽơ]�w�w�p��n�� scale �M bias�^
    fixed_point_t scale[TEST_SIZE] = {2.0, 0.5, -1.0, 1.5, 1.0};
    fixed_point_t bias[TEST_SIZE] = {1.0, -1.0, 0.5, -0.5, 0.0};

    // ��X�V�q
    fixed_point_t feature_out[TEST_SIZE];

    // ���� BatchNorm1d
    batch_norm1d(TEST_SIZE, feature_in, scale, bias, feature_out);

    // ��X���G
    std::cout << "BatchNorm1D Output:\n";
    for (int i = 0; i < TEST_SIZE; i++) {
        std::cout << feature_out[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
