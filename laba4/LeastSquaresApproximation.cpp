//
// Created by vadim on 06.11.2023.
//

#include "LeastSquaresApproximation.h"
vector<double> calculateA(const int& N, const int& m, const vector<int>& X, const vector<int>& Y){
    vector<double> POWERX(2 * m+1);

    for (int k = 0; k < 2 * m+1; k++) {
        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += pow(X[i], k);
        }
        POWERX[k] = sum;
    }

    vector<vector<double>> SUMX(m+1, vector<double>(m+1));

    for (int l = 0; l <m+1; l++) {
        for (int j = 0; j <m+1; j++) {
            SUMX[l][j] = POWERX[l + j];
        }
    }
    SUMX[0][0] = N;
    vector<double> PRAW(m+1);

    for (int l = 0; l <m+1; l++) {
        for (int i = 0; i < N; i++) {
            PRAW[l] += (Y[i] * pow(X[i], l));
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
        sum += yi*yi;
    }
    S*=sum;
    S = pow(S,0.5);
    return S;
}
void printResult(const vector<int>& X, const vector<int>& Y, const vector<double>& A, const double& S){
    cout << "X: ";
    for(const int& elem: X){
        cout << elem << " ";
    }
    cout << endl << "Y: ";
    for(const int& elem: Y){
        cout << elem << " ";
    }
    cout << endl;

    cout << "y = ";
    for(int j = A.size()-1; j >= 0; --j){
        cout << A[j];
        if(j > 0) {
            cout << "x^" << j;
            if(A[j - 1] >= 0) cout << " + ";
            else cout << " ";
        }
    }

    cout << endl << "S: " << S << endl;
}


