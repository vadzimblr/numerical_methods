//
// Created by vadim on 12.11.2023.
//

#include "writeDataToFile.h"
void writeVectorsToFile(const vector<int>& X,const vector<int>& Y,const vector<double>& A,const string& filename){
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return;
    }
    int xSize = X.size();
    for(int i = 0; i<xSize; i++){
        outputFile << X[i] << " ";
    }
    outputFile << "\n";
    int ySize = Y.size();
    for(int i = 0; i<ySize; i++){
        outputFile << Y[i] << " ";
    }
    outputFile << "\n";
    int aSize = A.size();
    for(int i = 0; i<aSize; i++){
        outputFile << A[i] << " ";
    }
    outputFile << "\n";
    outputFile.close();
    cout << "Данные успешно записаны в файл: " << filename << endl;
}


