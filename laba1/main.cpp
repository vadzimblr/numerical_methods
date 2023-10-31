#include <iostream>
#include <iomanip>
#include <vector>
#include "Gauss.h"
using namespace std;
int main() {
    system("chcp 65001");
    vector<vector<double>> matrix;
    vector<vector<double>> copy_matrix;
    vector<double> X, B,newX, newB, residualsVector;
    double RelativeError = 0;
    if (!fillMatrixByFile(matrix,B)) {
        return -1;
    }
    copy_matrix = matrix;
    printMatrix(matrix);
    cout << endl << endl;
    gauss(matrix,X);
    printAnswer(X);
    residualsVector = residuals(X,B,newB,copy_matrix);
    RelativeError = calculateRelativeError(X,newX,copy_matrix,B,newB);
    printAnswer(newX);
    cout << "Вектор невязки: " << endl;
    for(const double& elem: residualsVector){
        cout << setprecision(10)<<elem << " ";
    }
    cout << endl;
    cout << "Норма вектора невязки: " << endl <<calculateResidualNorm(residualsVector) << endl;
    cout << endl;
    cout << "Относительная погрешность: " <<endl;
    cout << RelativeError << endl;
    return 0;
}




