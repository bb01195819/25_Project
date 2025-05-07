#include <iostream>
#include "ap_fixed.h"

typedef ap_fixed<24,12> fixed_point_t;

// ���հѼ�
#define C 2   // �q�D��
#define H 4   // ����
#define W 4   // �e��

// �ŧi PReLU ���
void prelu(
    ap_uint<16> in_C, ap_uint<16> in_H, ap_uint<16> in_W,
    fixed_point_t feature_in[], fixed_point_t alpha[], fixed_point_t feature_out[]
);

int main() {
    // �]�w��J�S�x��
    fixed_point_t feature_in[C * H * W] = {
        1.0, -1.0, 2.0, -2.0,
        3.0, -3.0, 4.0, -4.0,
        5.0, -5.0, 6.0, -6.0,
        7.0, -7.0, 8.0, -8.0,

        -1.0, 1.0, -2.0, 2.0,
        -3.0, 3.0, -4.0, 4.0,
        -5.0, 5.0, -6.0, 6.0,
        -7.0, 7.0, -8.0, 8.0
    };

    // PReLU �Ѽơ]�Ĥ@�ӳq�D �\ = 0.1�A�ĤG�ӳq�D �\ = 0.5�^
    fixed_point_t alpha[C] = { 0.1, 0.5 };

    // ��X�S�x��
    fixed_point_t feature_out[C * H * W];

    // ���� PReLU
    prelu(C, H, W, feature_in, alpha, feature_out);

    // ��X���G
    std::cout << "PReLU Output:\n";
    for (int c = 0; c < C; c++) {
        std::cout << "Channel " << c << ":\n";
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                std::cout << feature_out[c * H * W + h * W + w] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
