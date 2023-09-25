#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool fillMatrixbyFile(double** matrix, int N, int M);
void printMatrix(double** matrix, int N, int M);
void Gauss(double** matrix, int N, int M);
void SwapLines(int line1, int line2, double** a);

int main()
{
    system("chcp 1251");
    int N = 3, M = 4;
    double** matrix = new double* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new double[M];
    }
    if (!fillMatrixbyFile(matrix, N, M)) {
        return -1;
    }

    printMatrix(matrix, N, M);
    cout << endl << endl;
    Gauss(matrix, N, M);

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

bool fillMatrixbyFile(double** matrix, int N, int M)
{
    ifstream inputFile("matrix.txt");
    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл!" << endl;
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();
    return true;
}

void printMatrix(double** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(15) << matrix[i][j];
        }
        cout << endl;
    }
}

void Gauss(double** matrix, int N, int M) {
    for (int k = 0; k < N; k++) {
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

    for (int k = N - 1; k >= 0; k--) {
        double koef = 0;
        if (matrix[k][k] == 0) {
            for (int i = k - 1; i >= 0; i--) {
                if (matrix[i][k] != 0) {
                    SwapLines(k, i, matrix);
                    break;
                }
            }
        }

        for (int i = k - 1; i >= 0; i--) {
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

    printMatrix(matrix, N, M);
}


void SwapLines(int line1, int line2, double** a)
{
    double* tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}
