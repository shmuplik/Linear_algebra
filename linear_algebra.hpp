#pragma once

struct Matrix{
    double** data2D;
    double* data;
    int dimension;
};

typedef unsigned int uint;

void outputArray(double* m, int s);
void output2Darray(double** m, int s);
Matrix matrix_input(bool flag = 1);
double det_computation(double** matrix, int dimension);
double** minor(double** matrix, int d, int k, int l);
int CramersRule(double** m1, int d1, double* m2, int d2);
int gcd(int a, int b);
int gcd_v2(int a, int b);
uint primecounts(uint n);