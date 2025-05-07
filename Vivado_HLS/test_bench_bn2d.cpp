#include <iostream>
#include "ap_fixed.h"

typedef ap_fixed<16,8> fixed_point_t;

// ���հѼ�
#define C 2   // �q�D��
#define H 4   // ����
#define W 4   // �e��

// �ŧi BatchNorm2d ���
void batch_norm2d(
    ap_uint<16> in_C, ap_uint<16> in_H, ap_uint<16> in_W,
    fixed_point_t feature_in[], fixed_point_t scale[], fixed_point_t bias[], fixed_point_t feature_out[]
);

int main() {
    // �]�w��J�S�x�� (������ 1.0)
    fixed_point_t feature_in[C * H * W];
    fixed_point_t scale[C];
    fixed_point_t bias[C];
    fixed_point_t feature_out[C * H * W];

    // ��l�ƿ�J�ƾ�
    for (int i = 0; i < C * H * W; i++) {
        feature_in[i] = 2.0;
    }

    // ��l�� BatchNorm �Ѽ�
    for (int i = 0; i < C; i++) {
        scale[i] = 2.0;  // �]�w `scale = 2`
        bias[i] = -1.0;  // �]�w `bias = -1`
    }

    // ���� BatchNorm2d
    batch_norm2d(C, H, W, feature_in, scale, bias, feature_out);

    // ��X���G
    std::cout << "BatchNorm2D Output:\n";
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
