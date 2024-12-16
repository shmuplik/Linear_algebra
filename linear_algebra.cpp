#include "linear_algebra.hpp"
#include <iostream>

#define FIRST_ROW 0



Matrix matrix_input(bool flag){
    double a;
    int startSize = 100;
    double *elements = new double[startSize];
    int amount = 0;
    while (std::cin >> a){
        elements[amount] = a;
        amount++;
        if (std::cin.peek() == '\n')
            break;
    }


    if (!flag)
        return {nullptr, elements, amount};

    int dimension = sqrt(amount);
    if (sqrt(amount) != dimension){
        delete[] elements;
        return {nullptr, nullptr, 0};

        
    }

    double** matrix = new double*[dimension];

    for (int i = 0; i < dimension; ++i)
        matrix[i] = new double[dimension];

    amount = 0;
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            matrix[i][j] = elements[amount++];  


    delete[] elements;
    
    return {matrix, nullptr, dimension};
    
}



void output2Darray(double** m, int s){
    for(int i = 0; i != s; ++i)
        for(int j = 0; j != s; ++j)
            std::cout << m[i][j] << ',';
    std::cout << '\n';
}

void outputArray(double* m, int s){
    for(int i = 0; i != s; ++i)
        std::cout << m[i] << ' ';
    std::cout << '\n';
}


double det_computation(double** matrix, int size){
    if (size == 1)
        return **matrix;
    double result = 0;
    for(int j = 0; j < size; ++j) {
        int add = size - 1;
        result += std::pow(-1,j) * 
        matrix[0][j] * 
        det_computation(minor(matrix, size, j, FIRST_ROW), add);

    }

    return result;
}


double** minor(double** m, int d, int k, int l){
    double** newMatrix = new double*[d-1];
    for (int i = 0; i < d-1; ++i)
        newMatrix[i] = new double[d-1];

    int newI = 0;
    for(int i = 0; i < d; ++i){
        if (i == l)
            continue;
        int newJ = 0;
        for(int j = 0; j < d; ++j){
            if (j == k)
                continue;
            newMatrix[newI][newJ] = m[i][j];
            ++newJ;
        }
        ++newI;
}

    return newMatrix;

}


int CramersRule(double** m1, int d1, double* m2, int d2){
    if (d1 != d2){
        std::cout << "demension of main matrix is "<< d1 <<
        "\ndemension of second matrix is " << d2 << std::endl;
        std::cout << "second matrix doesn't suit the first one\n" 
        << std::endl;
        return 0;
    }
    
    double delta = det_computation(m1,d1);
    if (!delta){
        std::cout << "det of main matrix = 0, can not use Cramer's Rule" 
        << std::endl;
        return 0;
    }
    std::cout << "det of main matrix is " << delta << std::endl;
    for(int k = 0; k < d1; ++k){

        double** add_matrix = new double*[d1];
        for (int i = 0; i < d1; ++i)
            add_matrix[i] = new double[d1];

        int c = 0;
        for(int i = 0; i < d1; ++i){
            for(int j = 0; j < d1; ++j){
                if (j == k)
                    add_matrix[i][k] = m2[c++];
                else
                    add_matrix[i][j] = m1[i][j];
            }
            
            
        }

        std::cout << "x" << k+1 << " = " << det_computation(add_matrix,d1)/delta << std::endl;
        for (int i = 0; i < d1; ++i)
            delete[] add_matrix[i];
    
        delete[] add_matrix;

    }
    std::cout << '\n';
    return 1;
}

int gcd(int a, int b){
    a = std::abs(a);
    b = std::abs(b);
    if (a%b == 0)
        return b;
    else
        return gcd(b, a%b);
    return gcd(a%b, b);
}

int gcd_v2(int a, int b){
    a = std::abs(a);
    b = std::abs(b);
    std::cout << "gcd(" << a << ", " << b << ") = ";
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    std::cout << a << std::endl;
    return a;
}

uint primecounts(uint n){
    bool* a = new bool[n+1];
    a[0] = 1; a[1] = 1;
    for(int i = 2; i <= sqrt(n); ++i)
        if (a[i] == 0)
            for(int j = i*i; j <= n; j += i)
                a[j] = 1;
    if (a[n] == 0){
        std::cout << n << " is prime\n";
        return n;}
    else{
        std::cout << n << " isn't prime\n";
        return n;}
    delete[] a;
}

