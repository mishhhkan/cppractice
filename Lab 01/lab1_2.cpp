#include <iostream>

int main() {
  int length;
  std::cout << "Введите количество целых чисел для ввода: ";
  std::cin >> length;
  int numbers[length];
  int numbers_asc[length];
  int numbers_desc[length];

  for (int i = 0; i < length; i++) {
    std::cout << "Введите " << i + 1 << " элемент списка: ";
    std::cin >> numbers[i];
    numbers_asc[i] = numbers[i];
    numbers_desc[i] = numbers[i];
  }

  // Вывод исходного списка
  std::cout << "Введённый список: ";
  for (int j = 0; j < length; j++) {
    std::cout << numbers[j];
  }
  std::cout << std::endl;

  std::cout << "Список, отсортированный по возрастанию: ";
  for (int j = 0; j < length; j++) {
    for (int i = 0; i < length - j - 1; i++) {
      if (numbers_asc[i] > numbers_asc[i + 1]) {
        int temp = numbers_asc[i];
        numbers_asc[i] = numbers_asc[i + 1];
        numbers_asc[i + 1] = temp;
      }
    }
    std::cout << numbers_asc[j];
  }
  std::cout << std::endl;

  std::cout << "Список, отсортированный по убыванию: ";
  for (int j = 0; j < length; j++) {
    for (int i = 0; i < length - j - 1; i++) {
      if (numbers_desc[i] < numbers_desc[i + 1]) {
        int temp = numbers_desc[i];
        numbers_desc[i] = numbers_desc[i + 1];
        numbers_desc[i + 1] = temp;
      }
    }
    std::cout << numbers_desc[j];
  }

  return 0;
}
