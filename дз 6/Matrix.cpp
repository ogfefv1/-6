//
//  Matrix.cpp
//  дз 6
//
//  Created by Егор Джемлиханов on 26.09.2024.
//


#include "Matrix.hpp"
#include <iostream>

using namespace std;

Matrix::Matrix() : str(0), st(0), ptr(nullptr) {}

Matrix::Matrix(int _str, int _st) : str(_str), st(_st)
{
    ptr = new int*[str];
    for (int i = 0; i < str; i++)
    {
        ptr[i] = new int[st] {0};
    }
}

Matrix::Matrix(const Matrix& arr) : str(arr.str), st(arr.st)
{
    ptr = new int*[str];
    for (int i = 0; i < str; i++)
    {
        ptr[i] = new int[st];
        for (int j = 0; j < st; j++)
        {
            ptr[i][j] = arr.ptr[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < str; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    cout << "Деструктор\n";
}

Matrix Matrix::SumMatrix(const Matrix& arr2)
{
    if (str != arr2.str || st != arr2.st)
    {
        cout << "Размеры не совпадают" << endl;
        return *this;
    }

    Matrix result(str, st);
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < st; j++)
        {
            result.ptr[i][j] = ptr[i][j] + arr2.ptr[i][j];
        }
    }
    return result;
}

Matrix Matrix::MultiMatrix(const Matrix& arr2)
{
    if (st != arr2.str)
    {
        cout << "Ошибка: st != str" << endl;
        return *this;
    }

    Matrix result(str, arr2.st);
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < arr2.st; j++)
        {
            result.ptr[i][j] = 0;
            for (int k = 0; k < st; k++)
            {
                result.ptr[i][j] += ptr[i][k] * arr2.ptr[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::TransposeMatrix()
{
    Matrix result(st, str);
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < st; j++)
        {
            result.ptr[j][i] = ptr[i][j];
        }
    }
    return result;
}

void Matrix::SetElement(int row, int col, int value)
{
    if (row >= 0 && row < str && col >= 0 && col < st)
    {
        ptr[row][col] = value;
    }
    else
    {
        cout << "Ошибка: неправильный индекс" << endl;
    }
}

int Matrix::GetElement(int row, int col)
{
    if (row >= 0 && row < str && col >= 0 && col < st)
    {
        return ptr[row][col];
    }
    else
    {
        cout << "Ошибка: неправильный индекс" << endl;
        return 0;
    }
}

void Matrix::Input()
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < st; j++)
        {
            ptr[i][j] = rand() % 100;
        }
    }
}

void Matrix::Print() const
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < st; j++)
        {
            cout << ptr[i][j] << "\t";
        }
        cout << endl << endl;
    }
}
