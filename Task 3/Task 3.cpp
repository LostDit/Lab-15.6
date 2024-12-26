#include <iostream>
#include <set>

void processInput() {
    setlocale(LC_ALL, "Russian");
    std::multiset<int> smallestNumbers; // Храним максимум 5 наименьших чисел
    int num;

    while (true) {
        std::cout << "Введите значение: ";
        std::cin >> num;

        if (num == -2) {
            std::cout << "Завершение программы" << std::endl;
            break;
        }

        if (num == -1) {
            // Если введено -1, нужно вывести пятое по возрастанию число
            if (smallestNumbers.size() < 5) {
                std::cout << "Недостаточно чисел для определения пятого" << std::endl;
            }else {
                auto it = smallestNumbers.begin();
                std::advance(it, 4); // Переходим к пятому элементу
                std::cout << "Пятое по возрастанию число: " << *it << std::endl;
            }
        }else {
            // Добавляем число в multiset
            smallestNumbers.insert(num);

            // Если в multiset больше 5 элементов, удаляем самый большой
            if (smallestNumbers.size() > 5) {
                auto it = --smallestNumbers.end(); // Находим наибольший элемент
                smallestNumbers.erase(it);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите числа (−1 для вывода пятого числа, −2 для завершения): ";
    processInput();
    return 0;
}