/*
Лабораторная работа №2, задание 2
Программисты: Гусев М. С., Патрушев А. В., Трубицын С. А.
Дата и время получения задания: 19.02.2026 09:55
Дата и время сдачи задания: 24.02.2026 11:40
*/

#include <iostream>

int main()
{
	std::cout << "Введите число в 10 СС: ";
	int number;
	std::cin >> number;
	std::cout << "Введите основание новой СС: ";
	int base;
	std::cin >> base;

	int temp[100];
	int index = 0;
	while (number > 0)
	{
		int c = number % base;
		number = number / base;
		temp[index] = c;
		index++;
	}

	for (int i = index - 1; i >= 0; i--)
	{
		std::cout << temp[i];
	}

	return 0;
}