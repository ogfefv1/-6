//
//  Matrix.hpp
//  дз 6
//
//  Created by Егор Джемлиханов on 26.09.2024.
//


#pragma once

class Matrix
{
    int** ptr;
    int str; // строки
    int st;  // столбцы

public:
    Matrix();
    Matrix(int _str, int _st);
    Matrix(const Matrix& arr);
    ~Matrix();

    Matrix SumMatrix(const Matrix& arr2);
    Matrix MultiMatrix(const Matrix& arr2);
    Matrix TransposeMatrix();

    void SetElement(int row, int col, int value);
    int GetElement(int row, int col);

    void Input();
    void Print() const;
};
