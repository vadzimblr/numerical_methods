#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool fillMatrixbyFile(vector<vector<double>>& matrix, vector<double>& B);
void printMatrix(const vector<vector<double>>& matrix);
void Gauss(vector<vector<double>>& matrix, vector<double>& X);
void SwapLines(int line1, int line2, vector<vector<double>>& a);
double calculateRelativeError(vector<double>& X,vector<double>& new_X, vector<vector<double>>& copy_matrix, vector<double>& B, vector<double>& new_B);
vector<double> getAnswer(const vector<vector<double>>& matrix ) ;
vector<double> residuals(const vector<double> &X, const vector<double>& B,vector<double>& new_B,const vector<vector<double>>& copy_matrix);

int main() {
    system("chcp 65001");
    vector<vector<double>> matrix;
    vector<vector<double>> copy_matrix;
    vector<double> X, B,new_X, new_B, residuals_vector;
    double RelativeError = 0;
    if (!fillMatrixbyFile(matrix,B)) {
        return -1;
    }
    copy_matrix = matrix;
    printMatrix(matrix);
    cout << endl << endl;
    Gauss(matrix,X);
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

double calculateRelativeError(vector<double>& X,vector<double>& new_X, vector<vector<double>>& copy_matrix, vector<double>& B, vector<double>& new_B){
    for(int i = 0; i<new_B.size();i++){
        copy_matrix[i][copy_matrix[0].size()-1]=new_B[i];
    }
    Gauss(copy_matrix,new_X);
    double max_difference,max_X = -10000;
    for(int i = 0; i<X.size();i++){
        if(max_difference < abs(new_X[i]-X[i])) {
            max_difference = abs(new_X[i] - X[i]);
        }
        if(max_X < abs(X[i])){max_X = abs(X[i]);}
    }
    return max_difference/max_X;
}


vector<double> residuals(const vector<double> &X, const vector<double>& B, vector<double>& new_B,const vector<vector<double>>& copy_matrix){
    vector<double> residuals;
    for(int i = 0; i<copy_matrix.size();i++){
        double result = 0;
        for(int j = 0; j<copy_matrix[i].size()-1;j++){
           result += copy_matrix[i][j]*X[j];
        }
        new_B.push_back(result);
        residuals.push_back(new_B[i]-B[i]);
    }
    return residuals;
}

bool fillMatrixbyFile(vector<vector<double>>& matrix, vector<double>& B) {
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

void Gauss(vector<vector<double>>& matrix, vector<double>& X) {
    int N = matrix.size();
    int M = matrix[0].size();

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

void SwapLines(int line1, int line2, vector<vector<double>>& a) {
    swap(a[line1], a[line2]);
}
