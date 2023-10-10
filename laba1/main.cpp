#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool fillMatrixbyFile(double** matrix, int N, int M);
void printMatrix(double** matrix, int N, int M);
void Gauss(double** matrix, int N, int M);
void SwapLines(int line1, int line2, double** a);
void printAnswer(double** matrix, int N, int M);
void printAnswer(double** matrix, int N, int M, double * B);
int main()
{
    //Создаем матрицу
    system("chcp 1251");
    int N = 3, M = 4;
    double** matrix = new double* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new double[M];
    }
    //Заполняем ее с файла
    if (!fillMatrixbyFile(matrix, N, M)) {
        return -1;
    }

    printMatrix(matrix, N, M);
    cout << endl << endl;
    Gauss(matrix, N, M);
    //Чистим память
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
//Заполнение матрицы с файла
bool fillMatrixbyFile(double** matrix, int N, int M)
{
    ifstream inputFile("/Users/vadzim/Desktop/числаки/1laba/matrix.txt");
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
    //Делаем нули под диагональю
    for (int k = 0; k < N-1; k++) {
        //koef - число на которое надо умножить к-ю строку чтобы разделить ее на на последующие с целью получения нулей
        double koef = 0;
        if (matrix[k][k] == 0) {//если опорный элемент равен нулю, то ищем строку, на которую можно поменять данную
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
        printMatrix(matrix, N, M);
    }
    double  * B = new double[N];
    printAnswer(matrix,N,M,B);
    delete [] B;
//    for (int k = N - 1; k >= 0; k--) {
//        double koef = 0;
//        if (matrix[k][k] == 0) {
//            for (int i = k - 1; i >= 0; i--) {
//                if (matrix[i][k] != 0) {
//                    SwapLines(k, i, matrix);
//                    break;
//                }
//            }
//        }
//
//        for (int i = k - 1; i >= 0; i--) {
//            koef = matrix[i][k] / matrix[k][k];
//            for (int j = k; j < M; j++) {
//                matrix[i][j] = matrix[i][j] - matrix[k][j] * koef;
//            }
//        }
//    }
    //Делаем единицы на главной диагонали и получаем ответ

//    printAnswer(matrix, N, M);
    
}

void printAnswer(double** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        cout << "x"<<i+1<<": " << matrix[i][M - 1]<< endl;
    }
}
void printAnswer(double** matrix, int N, int M, double * B){
    B[N-1] = matrix[N-1][M-1];
    for(int i = N-2; i>-1;i--){
        double sum = 0;
        for(int k=i+1; k<N; k++){
            sum += matrix[i][k] * B[k];
        }
        B[i] = matrix[i][N] - sum;
    }
    
    for (int i = 0; i < N; i++){
        cout << "x" << i+1 << ": " << B[i] << endl;
    }
}
void SwapLines(int line1, int line2, double** a)
{
    double* tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}
