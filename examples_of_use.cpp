#include <iostream>
#include <cmath>
#include "linear_algebra.hpp"

/*
подсчет определитлей осуществлен для вещественных чисел
НОД для всех целых
ввод матрицы с клавитуры
    пример ввода: 1 2 3 4
    матрица:
        |1 2|
        |3 4|


ввод с файла в консоли 
Windows: ./a.exe < ./test.txt 
macOS/Linux: ./a.out < ./test.txt 

НОД реализован через рекурсию и через цикл

*/




int main(){

    /*
    все числа выбраны при помощи random.org
    подсчет определителя 3x3:


    |661  -52  -632|
    |292  -266  486|
    |490   678  653|
    
    = -5.42583e+08 (-542583006 - согласно Photomath)

    в консоли на вход подаем input.txt
    или вводим матрицу с клавиатуры через пробел

    */

   std::cout << "Examples of using fucntion - det_computation:\n";

    //вызов ввода матрицы
    Matrix exmapleMatrix1 = matrix_input();
    //проверка на подлость
    if (exmapleMatrix1.data2D == nullptr && 
    exmapleMatrix1.data == nullptr)
        std::cout << "matrix is not quadratic\n";
    else
        std::cout << det_computation(exmapleMatrix1.data2D, 
    exmapleMatrix1.dimension) << '\n';


    //deleting
    for (int i = 0; i < exmapleMatrix1.dimension; ++i)
        delete[] exmapleMatrix1.data2D[i];
    delete[] exmapleMatrix1.data2D;

    

    
    /*
    //подсчет определителя 5x5:

    | 32   150 -155 -200 -52 | 
    | 242  924  728  137 -237|
    | 931 -89  -111  129  742|
    |-234  128  983  238 -199|
    | 284  239 -900  456  76 |

    = -3.22547e+12 (-3225466472051)

    */

    Matrix exmapleMatrix2 = matrix_input();
    if (exmapleMatrix2.data2D == nullptr && 
    exmapleMatrix2.data == nullptr)
        std::cout << "matrix is not quadratic\n";
    else
        std::cout << det_computation(exmapleMatrix2.data2D, 
    exmapleMatrix2.dimension) << '\n';

    for (int i = 0; i < exmapleMatrix2.dimension; ++i)
        delete[] exmapleMatrix2.data2D[i];
    delete[] exmapleMatrix2.data2D;

    /*
    //подсчет определителя 7x7:

    | 899  832  84   111 -233 -949  305|
    |-469  438 -39  -559  766 -80  -120|
    | 476  189  876  338  153 -848  151|
    |-334  506 -435  190  221  208 -947|
    |-523 -643  841  27  -431  954 -913|
    |-206  239 -777 -320  694  273  218|
    |-775 -88  -685 -213  666 -604  929|

    = -1.27259e+20 (Photomath не справился)
    результат проверен (на другом онлайн сервисе)

    */

    Matrix exmapleMatrix3 = matrix_input();
    if (exmapleMatrix3.data2D == nullptr && 
    exmapleMatrix3.data == nullptr)
        std::cout << "matrix is not quadratic\n";
    else
        std::cout << det_computation(exmapleMatrix3.data2D, 
    exmapleMatrix3.dimension) << '\n';

    for (int i = 0; i < exmapleMatrix3.dimension; ++i)
        delete[] exmapleMatrix3.data2D[i];
    delete[] exmapleMatrix3.data2D;

    /*
    //подсчет определителя 2x3:

    |3 2 2| 
    |1 7 8|

    = ...

    */

    Matrix exmapleMatrix4 = matrix_input();
    if (exmapleMatrix4.data2D == nullptr && 
    exmapleMatrix4.data == nullptr)
        std::cout << "matrix is not quadratic\n";
    else
        std::cout << det_computation(exmapleMatrix4.data2D, 
    exmapleMatrix4.dimension) << '\n';

    for (int i = 0; i < exmapleMatrix4.dimension; ++i)
        delete[] exmapleMatrix4.data2D[i];
    delete[] exmapleMatrix4.data2D;

   
    /*
    пример использования метода Крамера для матрицы 3x3:

    (661  -52  -632)   (x1)   (-94 )
    (292  -266  486) * (x2) = (-142)
    (490   678  653)   (x3)   ( 258)


    */
    std::cout << "\nExamples of using Cramer's Rule:\n";

    Matrix matrix1 = matrix_input();
    Matrix Smatrix1 = matrix_input(0);

    CramersRule(matrix1.data2D, matrix1.dimension, Smatrix1.data, 
    Smatrix1.dimension);

    for (int i = 0; i < matrix1.dimension; ++i)
        delete[] matrix1.data2D[i];
    delete[] matrix1.data2D;
    delete[] Smatrix1.data;


    /*
    пример с матрицами
    с несоответсвующей размерностью:

    (661  -52  -632)   (x1)   (-94 )
    (292  -266  486) * (x2) = (-142)
    (490   678  653)   (x3)   (    )


    */

    Matrix matrix2 = matrix_input();
    Matrix Smatrix2 = matrix_input(0);

    CramersRule(matrix2.data2D, matrix2.dimension, Smatrix2.data, 
    Smatrix2.dimension);

    for (int i = 0; i < matrix2.dimension; ++i)
        delete[] matrix2.data2D[i];
    delete[] matrix2.data2D;
    delete[] Smatrix2.data;






    /*
    пример использования метода Крамера для матрицы Вандермонда
    c двумя одинаковыми строчками
    (1   2   4    8)      (x1)   (-135)
    (1   2   4    8)   *  (x2) = (-94 )
    (1  15 225 3375)      (x3)   (-142)
    (1  14 196 2744)      (x4)   ( 258)


    */

    Matrix matrix3 = matrix_input();
    Matrix Smatrix3 = matrix_input(0);

    CramersRule(matrix3.data2D, matrix3.dimension, Smatrix3.data, 
    Smatrix3.dimension);

    for (int i = 0; i < matrix3.dimension; ++i)
        delete[] matrix3.data2D[i];
    delete[] matrix3.data2D;
    delete[] Smatrix3.data;


    std::cout << "\nExamples of using GCD:\n";

    /*
        пример использования алгоритма Евклида (НОД)

        НОД(-976289, 162056)

        функция берет модули этих чисел
        написана с рекурсией
    
    */

    int x1, x2;
    std::cin >> x1 >> x2;

    std::cout << "gcd(" << x1 << ", " << x2 << ") = " << gcd(x1,x2)
    << std::endl;

    /*
        пример использования алгоритма Евклида (НОД)

        НОД(-655104, -448497)

        написана циклом
    
    */

    int x3, x4;
    std::cin >> x3 >> x4;

    gcd_v2(x3,x4);

    /*
        решето Эратосфена

        простое ли число 11161?
    
    */

    std::cout << "\nExamples of using Sieve of Eratosthenes:\n";

    uint x5;
    std::cin >> x5;
    primecounts(x5);

    /*
        решето Эратосфена

        простое ли число 276947?
    
    */

    uint x6;
    std::cin >> x6;
    primecounts(x6);




    
    }
    






