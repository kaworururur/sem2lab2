#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    double* array;
    int size;

public:
    Vector();
    Vector(int n, double* arr);
    Vector(int n);
    Vector(const Vector& obj); // Конструктор копирования
    Vector(Vector&& obj) noexcept; // Конструктор перемещения
    ~Vector();

    double& operator[](int index);
    Vector& operator=(const Vector& obj); // Присваивание с копированием
    Vector& operator=(Vector&& obj); // Присваивание с перемещением

    friend std::ostream& operator<<(std::ostream& os, const Vector& obj);
    friend std::istream& operator>>(std::istream& is, Vector& obj);
    Vector operator+(const Vector& obj1); // Перегрузка операции сложения векторов
};

#endif