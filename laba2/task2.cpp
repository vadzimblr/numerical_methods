#include <iostream>
#include <iomanip>
#include "Gauss.h"
#include <vector>
using namespace std;
double get_d1(const vector<double>& x);
double get_d2(const vector<double>& x, const vector<double>& x_Kplus1);
double funtion_1(const double& x0_1, const double& x0_2);
double funtion_2(const double& x0_1, const double& x0_2);
double J_1dx0_1(const double& x0_1, const double& x0_2);
double J_1dx0_2(const double& x0_1, const double& x0_2);
double J_2dx0_1(const double& x0_1, const double& x0_2);
double J_2dx0_2(const double& x0_1, const double& x0_2);
void Jakobian_method_1(double** matrix, const vector<double>& x);
void Jakobian_method_2(double** matrix, const vector<double>& x, const double& M);
int main()
{
	//system("chcp 1251");
	const double eps = 1e-9;
	double  d1 = 1, d2 = 1;
	vector<double> x;	
	x.push_back(-1.5);
	x.push_back(1.5);
	vector<double> x_Kplus1(x);
	int k = 1;
	int NIT = 100;
	int N = 2;
	int M = 3;
	double M_parametr = 0.1;
	double** matrix = new double* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new double[M];
	}
	double* ans = new double[N];
	while ((d1 > eps || d2 > eps) && k < NIT)
	{
		Jakobian_method_1(matrix, x);
		//Jakobian_method_2(matrix, x, M_parametr);
		matrix[0][2] = -funtion_1(x[0], x[1]);
		matrix[1][2] = -funtion_2(x[0], x[1]);
		getAnswerGauss(matrix, N, M, ans);
		x_Kplus1[0] += ans[0];
		x_Kplus1[1] += ans[1];
		
		d1 = get_d1(x);
		d2 = get_d2(x, x_Kplus1);
		cout << "Итерация:" << k << " d1: " << d1 << " d2: " << d2 << endl;
		k++;
		x = x_Kplus1;		
	}
	//261886462 0.01
	//261890459 0.05
	//261947396 0.1
	cout << "Решение: x = " << setprecision(25) <<x[0] << ", y = " << x[1] << endl << "Кол-во итераций: " << k << endl;
	delete[] ans;
	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
double get_d1(const vector<double>& x) {
	double f1 = funtion_1(x[0], x[1]);
	double f2 = funtion_2(x[0], x[1]);
	if (abs(f1) > abs(f2))
		return abs(f1);
	else
		return abs(f2);

}
double get_d2(const vector<double>& x, const vector<double>& x_Kplus1) {
	double max = -9999999;
	for (int i = 0; i < x.size(); i++) {
		if (abs(x_Kplus1[i]) < 1)
		{
			if (abs(x_Kplus1[i] - x[i]) > max)
				max = abs(x_Kplus1[i] - x[i]);
		}
		else
		{
			if (abs((x_Kplus1[i] - x[i]) / x_Kplus1[i]) > max)
				max = abs((x_Kplus1[i] - x[i]) / x_Kplus1[i]);
		}
	}
	return max;
}
double funtion_1(const double& x0_1, const double& x0_2) {
	return x0_1 * x0_1 * x0_2 * x0_2 - 3 * x0_1 * x0_1 - 6 * x0_2 * x0_2 * x0_2 + 8;
}
double funtion_2(const double& x0_1, const double& x0_2) {
	return x0_1 * x0_1 * x0_1 * x0_1 - 9 * x0_2 + 2;
}
double J_1dx0_1(const double& x0_1, const double& x0_2) {
	return 2 * x0_1 * x0_2 * x0_2 - 6 * x0_1;
}
double J_1dx0_2(const double& x0_1, const double& x0_2) {
	return 2 * x0_2 * x0_1 * x0_1 - 18 * x0_2 * x0_2;
}
double J_2dx0_1(const double& x0_1, const double& x0_2) {
	return 3 * x0_1 * x0_1 * x0_1;
}
double J_2dx0_2(const double& x0_1, const double& x0_2) {
	return -9;
}
void Jakobian_method_1(double** matrix, const vector<double> &x) {
	matrix[0][0] = J_1dx0_1(x[0], x[1]);
	matrix[0][1] = J_1dx0_2(x[0], x[1]);
	matrix[1][0] = J_2dx0_1(x[0], x[1]);
	matrix[1][1] = J_2dx0_2(x[0], x[1]);
}
void Jakobian_method_2(double** matrix, const vector<double>& x, const double& M) {
	matrix[0][0] = (funtion_1(x[0]+M*x[0], x[1]) - funtion_1(x[0], x[1]))/ M * x[0];
	matrix[0][1] = (funtion_1(x[0], x[1] + +M * x[1]) - funtion_1(x[0], x[1])) / M * x[1];
	matrix[1][0] = (funtion_2(x[0] + M * x[0], x[1]) - funtion_2(x[0], x[1])) / M * x[0];
	matrix[1][1] = (funtion_2(x[0], x[1] + +M * x[1]) - funtion_2(x[0], x[1])) / M * x[1];;
}