//
// Created by Вадзім Пазняк on 31.10.23.
//

#include "Gauss.h"
void gauss(vector<vector<double>>& matrix, vector<double>& X) {
    int N = matrix.size();
    int M = matrix[0].size();

    for (int k = 0; k < N - 1; k++) {
        double koef = 0;

        if (matrix[k][k] == 0) {
            for (int i = k + 1; i < N; i++) {
                if (matrix[i][k] != 0) {
                    swapLines(k, i, matrix);
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

    X = getAnswer(matrix);
}

vector<double> getAnswer(const vector<vector<double>>& matrix ) {
    int N = matrix.size();
    int M = matrix[0].size();
    vector<double> temp(N);

    for (int i = N - 1; i >= 0; i--) {
        double sum = matrix[i][M - 1];
        for (int j = i + 1; j < N; j++) {
            sum -= matrix[i][j] * temp[j];
        }
        temp[i] = sum / matrix[i][i];
    }
    return temp;
}

void swapLines(int line1, int line2, vector<vector<double>>& a) {
    swap(a[line1], a[line2]);
}

void printAnswer(const vector<double>& X){
    for (int i =0; i<X.size();i++) {
        cout <<setprecision(20) <<"A["<<i+1<<"]: " << X[i]<<endl;
    }
    cout <<endl;
}