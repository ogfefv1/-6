//
//  main.cpp
//  дз 6
//
//  Created by Егор Джемлиханов on 25.09.2024.
//


#include<iostream>
#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix obj1(3, 5);
    obj1.Input();
    obj1.Print();

    Matrix obj2(5, 10);
    obj2.Input();
    obj2.Print();

    Matrix sumMatrix = obj1.SumMatrix(obj2);
    sumMatrix.Print();

    Matrix multiMatrix = obj1.MultiMatrix(obj2);
    multiMatrix.Print();

    Matrix transposedMatrix = obj1.TransposeMatrix();
    transposedMatrix.Print();

    return 0;
}
