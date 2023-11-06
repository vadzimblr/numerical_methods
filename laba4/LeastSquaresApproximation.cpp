//
// Created by vadim on 06.11.2023.
//

#include "LeastSquaresApproximation.h"
vector<double> calculateA(const int& N, const int& m, const vector<int>& X, const vector<int>& Y){
    vector<double> POWERX(2 * m);

    for (int k = 0; k <= 2 * m; k++) {
        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += pow(X[i], k + 1);
        }
        POWERX[k] = sum;
    }

    vector<vector<double>> SUMX(m + 1, vector<double>(m + 1));

    for (int l = 0; l <= m; l++) {
        for (int j = 0; j <= m; j++) {
            SUMX[l][j] = POWERX[l + j];
        }
    }
    SUMX[0][0] = N;
    vector<double> PRAW(m + 1);

    for (int l = 0; l <= m; l++) {
        for (int i = 0; i < N; i++) {
            PRAW[l] += (Y[i] * pow(X[i], l + 1));
        }
    }

    int matrixISize =  PRAW.size();
    int matrixJSize = SUMX.size() + 1 ;
    vector<vector<double>> matrix(matrixISize, vector<double>(matrixJSize));

    for (int i = 0; i < matrixISize; i++) {
        for (int j = 0; j < matrixJSize; j++) {
            if (j == matrixJSize - 1) {
                matrix[i][j] = PRAW[i];
            } else {
                matrix[i][j] = SUMX[i][j];
            }
        }
    }
    vector<double> A;
    gauss(matrix, A);
    return A;

}
double calculateS(const int& N, const int& m, const vector<int>& X, const vector<int>& Y, const vector<double>& A){
    double S = 1.0/(N-m-1);
    double sum = 0;
    for(int i=0; i<N; i++){
        double yi = Y[i];
        for(int j = 0; j<m+1;j++){
            yi-= A[j] * pow(X[i],j);
        }
        sum += yi;
    }
    S*=(sum*sum);
    S = pow(S,0.5);
    return S;
}

void printResult(const vector<int>& X, const vector<int>& Y,const vector<double>& A, const double& S){
    cout << "X: ";
    for(const int& elem: X){
        cout << elem << " ";
    }
    cout << endl << "Y: ";
    for(const int& elem: Y){
        cout << elem << " ";
    }
    cout << endl;
    printAnswer(A);
    cout << "y = " << A[2] << "x^2 + " << A[1] << "x + " << A[0] << endl;
    cout << "S: " << S << endl;
}


