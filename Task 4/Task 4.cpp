#include <iostream>
#include <vector>
#include <cmath>

void printSortedByAbs(const std::vector<int>& a) {
    int n = a.size();

    // Найдём индекс первого неотрицательного элемента
    int posIndex = 0;
    while (posIndex < n && a[posIndex] < 0) {
        posIndex++;
    }

    // Устанавливаем два указателя:
    int negIndex = posIndex - 1; // Указатель на последний отрицательный элемент
    int i = 0;

    // Одновременный проход влево и вправо
    while (negIndex >= 0 && posIndex < n) {
        if (std::abs(a[negIndex]) <= std::abs(a[posIndex])) {
            std::cout << a[negIndex] << " ";
            negIndex--;
        }
        else {
            std::cout << a[posIndex] << " ";
            posIndex++;
        }
    }

    // Если остались элементы слева
    while (negIndex >= 0) {
        std::cout << a[negIndex] << " ";
        negIndex--;
    }

    // Если остались элементы справа
    while (posIndex < n) {
        std::cout << a[posIndex] << " ";
        posIndex++;
    }

    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> a = { -100, -50, -5, 1, 10, 15 };

    std::cout << "Исходный массив: ";
    for (int num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив, отсортированный по модулю: ";
    printSortedByAbs(a);

    return 0;
}