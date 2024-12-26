#include "vector.h"

Vector::Vector() : array(nullptr), size(0) {}

Vector::Vector(int n, double* arr) : size(n) {
    array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = arr[i];
    }
}

Vector::Vector(int n) {
    this->size = n;
    this->array = new double[n];
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
}

Vector::Vector(const Vector& obj) : size(obj.size) {
    array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = obj.array[i];
    }
}

Vector::Vector(Vector&& obj) noexcept : array(obj.array), size(obj.size) {
    obj.array = nullptr;
    obj.size = 0;
}

Vector::~Vector() {
    delete[] array;
}

double& Vector::operator[](int index) {
    return array[index];
}

Vector& Vector::operator=(const Vector& obj) {
    if (this == &obj) {
        return *this;
    }

    delete[] array;
    size = obj.size;
    array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = obj.array[i];
    }

    return *this;
}

Vector& Vector::operator=(Vector&& obj) {
    if (this == &obj) {
        return *this;
    }

    delete[] array;
    array = obj.array;
    size = obj.size;
    obj.array = nullptr;
    obj.size = 0;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& obj) {
    for (int i = 0; i < obj.size; i++) {
        os << obj.array[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& obj) {
    for (int i = 0; i < obj.size; i++) {
        is >> obj.array[i];
    }
    return is;
}

Vector Vector::operator+(const Vector& obj1) {

    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.array[i] = obj1.array[i] + array[i];
    }

    return result;
}