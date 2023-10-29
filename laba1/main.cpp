#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool fillMatrixByFile(vector<vector<double>>& matrix, vector<double>& B);
void printMatrix(const vector<vector<double>>& matrix);
void gauss(vector<vector<double>>& matrix, vector<double>& X);
void swapLines(int line1, int line2, vector<vector<double>>& a);
double calculateRelativeError(vector<double>& X, vector<double>& newX, vector<vector<double>>& copyMatrix, vector<double>& B, vector<double>& newB);
vector<double> getAnswer(const vector<vector<double>>& matrix);
vector<double> residuals(const vector<double>& X, const vector<double>& B, vector<double>& newB, const vector<vector<double>>& copyMatrix);


int main() {
    system("chcp 65001");
    vector<vector<double>> matrix;
    vector<vector<double>> copy_matrix;
    vector<double> X, B,new_X, new_B, residuals_vector;
    double RelativeError = 0;
    if (!fillMatrixByFile(matrix,B)) {
        return -1;
    }
    copy_matrix = matrix;
    printMatrix(matrix);
    cout << endl << endl;
    gauss(matrix,X);
    residuals_vector = residuals(X,B,new_B,copy_matrix);
    RelativeError = calculateRelativeError(X,new_X,copy_matrix,B,new_B);
    cout << endl;
    cout << "Вектор невязки: " << endl;
    for(const double& elem: residuals_vector){
        cout<<elem << " ";
    }
    cout << endl;
    cout << "Относительная погрешность: " <<endl;
    cout << RelativeError << endl;
    return 0;
}

double calculateRelativeError(vector<double>& X, vector<double>& newX, vector<vector<double>>& copyMatrix, vector<double>& B, vector<double>& newB){
    for(int i = 0; i<newX.size();i++){
        copyMatrix[i][copyMatrix[0].size()-1]=newX[i];
    }
    gauss(copyMatrix,newX);
    double max_difference,max_X = -10000;
    for(int i = 0; i<X.size();i++){
        if(max_difference < abs(newX[i]-X[i])) {
            max_difference = abs(newX[i] - X[i]);
        }
        if(max_X < abs(X[i])){max_X = abs(X[i]);}
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

bool fillMatrixByFile(vector<vector<double>>& matrix, vector<double>& B) {
    ifstream inputFile(R"(C:\Users\vadim\CLionProjects\numerical_methods\laba1\matrix.txt)");
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
    for (const auto& row : matrix) {
        for (const double& val : row) {
            cout << setw(15) << val;
        }
        cout << endl;
    }
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

    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << ": " << temp[i] << endl;
    }
    return temp;
}

void swapLines(int line1, int line2, vector<vector<double>>& a) {
    swap(a[line1], a[line2]);
}
