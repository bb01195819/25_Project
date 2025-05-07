#include <iostream>
#include "ap_fixed.h"

// �ϥ� INT16 �w�I��
typedef ap_fixed<16,8> fixed_point_t;

// ���հѼ�
#define TEST_SIZE 5   // ���զV�q�j�p

// �ŧi Element-wise Add ���
void elementwise_add(
    ap_uint<16> size, fixed_point_t input1[], fixed_point_t input2[], fixed_point_t output[]
);

int main() {
    // �]�w��J�V�q
    fixed_point_t input1[TEST_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
    fixed_point_t input2[TEST_SIZE] = {0.5, -0.5, 1.5, -1.5, 0.0};

    // ��X�V�q
    fixed_point_t output[TEST_SIZE];

    // ���� Element-wise Add
    elementwise_add(TEST_SIZE, input1, input2, output);

    // ��X���G
    std::cout << "Element-wise Add Output:\n";
    for (int i = 0; i < TEST_SIZE; i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
