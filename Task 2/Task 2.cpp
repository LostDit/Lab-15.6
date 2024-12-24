#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

std::pair<int, int> findTwoNumbersWithSum(const std::vector<int>& a, int target) {
    setlocale(LC_ALL, "Russian");
    std::unordered_map<int, int> seen; // Словарь для хранения чисел и их индексов

    for (int num : a) {
        int complement = target - num; // Второе число, необходимое для получения суммы
        if (seen.count(complement)) {
            return { complement, num }; // Нашли пару чисел
        }
        seen[num] = 1; // Сохраняем текущее число в словарь
    }

    throw std::invalid_argument("Пара чисел с заданной суммой не найдена");
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> a = { 2, 7, 11, 15 };
    int target = 9;

    try {
        auto [num1, num2] = findTwoNumbersWithSum(a, target);
        std::cout << "Числа: " << num1 << " и " << num2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
