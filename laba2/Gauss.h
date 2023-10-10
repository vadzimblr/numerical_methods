#pragma once
void Gauss(double** matrix, int N, int M);
void SwapLines(int line1, int line2, double** a);
void getAnswerGauss(double** matrix, int N, int M, double* B);

void Gauss(double** matrix, int N, int M) {
    for (int k = 0; k < N - 1; k++) {   
        double koef = 0;
        if (matrix[k][k] == 0) {
            for (int i = k + 1; i < N; i++) {
                if (matrix[i][k] != 0) {
                    SwapLines(k, i, matrix);
                    break;
                }
            }
        }
        for (int i = k + 1; i < N; i++) {
            koef = matrix[i][k] / matrix[k][k];
            for (int j = k; j < M; j++) {
                matrix[i][j] = matrix[i][j] - matrix[k][j] * koef;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        double diagElement = matrix[i][i];
        for (int j = i; j < M; j++) {
            matrix[i][j] /= diagElement;
        }
    }
    
}

void getAnswerGauss(double** matrix, int N, int M, double* B) {
    Gauss(matrix, N, M);
    B[N - 1] = matrix[N - 1][M - 1];
    for (int i = N - 2; i > -1; i--) {
        double sum = 0;
        for (int k = i + 1; k < N; k++) {
            sum += matrix[i][k] * B[k];
        }
        B[i] = matrix[i][N] - sum;
    }
}
void SwapLines(int line1, int line2, double** a)
{
    double* tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}