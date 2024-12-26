#include <iostream>
#include <fstream>
#include "vector.h"

int main() {
    // Чтение из файла input.txt
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    int size;
    input_file >> size;
    double* data = new double[size];
    for (int i = 0; i < size; i++) {
        input_file >> data[i];
    }
    input_file.close();


    std::cout << "1" << data[1] << std::endl;
    // Создание векторов
    Vector vec1(size, data);
    Vector vec2(size, data);

    std::cout << "1";
    // Произведение операции сложения векторов
    Vector sum_vector = vec1 + vec2;

    std::cout << "1";
    // Запись результата в output.txt
    std::ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }
    std::cout << "1";
    output_file << "Vector 1 elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        output_file << vec1[i] << " ";
    }
    output_file << std::endl;

    output_file << "Vector 2 elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        output_file << vec2[i] << " ";
    }
    output_file << std::endl;

    output_file << "Sum of vectors elements:" << std::endl;
    for (int i = 0; i < size; i++) {
        output_file << sum_vector[i] << " ";
    }
    //output_file << std::endl;

    output_file.close();
    delete[] data;

    return 0;
}