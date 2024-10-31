#include <stdio.h>

#define MATRIX_SIZE 8
#define KERNEL_SIZE 3

void convolve2D(float matrix[MATRIX_SIZE][MATRIX_SIZE], float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[MATRIX_SIZE - KERNEL_SIZE + 1][MATRIX_SIZE - KERNEL_SIZE + 1]) {
    int output_size = MATRIX_SIZE - KERNEL_SIZE + 1;

    for (int i = 0; i < output_size; i++) {
        for (int j = 0; j < output_size; j++) {
            float sum = 0.0;
            for (int ki = 0; ki < KERNEL_SIZE; ki++) {
                for (int kj = 0; kj < KERNEL_SIZE; kj++) {
                    sum += matrix[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            output[i][j] = sum;
        }
    }
}

int main() {
    // Define the input matrix (8x8)
    float input_matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {0.17, 0.95, 0.64, -0.70, -0.81, -0.30, 0.06, -0.05},
        {0.79, 0.03, 0.69, 0.43, 0.86, -0.08, 0.54, -0.37},
        {0.81, 0.30, 0.40, 0.78, -0.34, 0.08, -0.73, 0.74},
        {0.59, -0.89, 0.39, 0.22, -0.56, 0.22, 0.10, 0.60},
        {0.17, 0.34, 0.47, 0.67, -0.24, 0.00, 0.33, -0.94},
        {0.58, 0.68, 0.67, -0.59, 0.57, 0.39, -0.66, 0.53},
        {-0.79, 0.54, 0.47, 0.94, 0.64, 0.72, -0.73, 0.03},
        {-0.64, 0.38, 0.92, -0.85, 0.71, 0.14, 0.38, 0.21}
    };

    // Define the kernel (3x3)
    float kernel[KERNEL_SIZE][KERNEL_SIZE] = {
        {-0.30, -0.85, 0.06},
        {-0.95, 0.21, 0.36},
        {0.22, -0.07, 0.59}
    };

    float output_matrix[MATRIX_SIZE - KERNEL_SIZE + 1][MATRIX_SIZE - KERNEL_SIZE + 1];

    convolve2D(input_matrix, kernel, output_matrix);

    printf("Output Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE - KERNEL_SIZE + 1; i++) {
        for (int j = 0; j < MATRIX_SIZE - KERNEL_SIZE + 1; j++) {
            printf("%f ", output_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
