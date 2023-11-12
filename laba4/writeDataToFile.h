//
// Created by vadim on 12.11.2023.
//

#ifndef NUMERICAL_METHODS_WRITEDATATOFILE_H
#define NUMERICAL_METHODS_WRITEDATATOFILE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void writeVectorsToFile(const vector<int>& X,
                        const vector<int>& Y,
                        const vector<double>& A,
                        const string& filename);


#endif //NUMERICAL_METHODS_WRITEDATATOFILE_H
