#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept> // Для std::invalid_argument

std::pair<int, int> findMaxSubarrayIndices(const std::vector<int>& a) {
    if (a.empty()) {
        throw std::invalid_argument("Массив не должен быть пустым");
    }

    int maxSum = INT_MIN; // Максимальная сумма
    int currentSum = 0;   // Текущая сумма
    int start = 0, end = 0, tempStart = 0; // Инициализация индексов

    for (int i = 0; i < a.size(); ++i) {
        currentSum += a[i];

        // Если нашли новую максимальную сумму, обновляем индексы
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        // Если текущая сумма становится отрицательной, начинаем новую последовательность
        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    return { start, end };
}

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        std::vector<int> a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }, b = { 1,34,2,3,-2,-3,12,22,34 }; //Просто для теста создал несколько массивов
        auto [start, end] = findMaxSubarrayIndices(a); // Используем C++17 в отладке
        std::cout << "Индексы: " << start << ", " << end << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
