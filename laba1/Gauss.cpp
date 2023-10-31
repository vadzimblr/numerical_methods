//
// Created by Вадзім Пазняк on 31.10.23.
//

#include "Gauss.h"
double calculateRelativeError(vector<double>& X, vector<double>& newX, vector<vector<double>>& copyMatrix, vector<double>& B, vector<double>& newB){
    for(int i = 0; i<copyMatrix.size();i++){
        copyMatrix[i][copyMatrix.size()]=newB[i];
    }
    gauss(copyMatrix,newX);
    double max_difference = fabs(newX[0]-X[0]);
    double max_X = fabs(X[0]);
    for(int i = 1; i<X.size();i++){
        if(max_difference < fabs(newX[i]-X[i])) {
            max_difference = fabs(newX[i] - X[i]);
        }
        if(max_X < fabs(X[i])){max_X = fabs(X[i]);}
    }
    return max_difference/max_X;
}


vector<double> residuals(const vector<double>& X, const vector<double>& B, vector<double>& newB, const vector<vector<double>>& copyMatrix){
    vector<double> residuals;
    for(int i = 0; i<copyMatrix.size();i++){
        double result = 0;
        for(int j = 0; j<copyMatrix[i].size()-1;j++){
            result += copyMatrix[i][j]*X[j];
        }
        newB.push_back(result);

        residuals.push_back(newB[i]-B[i]);
    }
    return residuals;
}
double calculateResidualNorm(const vector<double>& residuals){
    double max = abs(residuals[0]);
    for(int i = 1; i<residuals.size();i++){
        if(max<abs(residuals[i])){
            max = abs(residuals[i]);
        }
    }
    return max;
}
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
        cout << endl;
        printMatrix(matrix);
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
bool fillMatrixByFile(vector<vector<double>>& matrix, vector<double>& B) {
    ifstream inputFile(R"(/Users/vadzim/Desktop/числаки/numerical_methods/laba1/matrix.txt)");
    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл!" << endl;
        return false;
    }
    int N, M;
    inputFile >> N >> M;
    matrix.resize(N, vector<double>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            inputFile >> matrix[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        B.push_back(matrix[i][M-1]);
    }
    inputFile.close();
    return true;
}

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto & row : matrix) {
        for (const double& val : row) {
            cout<< setw(30) << val;
        }
        cout << endl;
    }
}
void printAnswer(const vector<double>& X){
    for (int i =0; i<X.size();i++) {
        cout <<setprecision(20) <<"x["<<i+1<<"]: " << X[i]<<endl;
    }
    cout <<endl;
}