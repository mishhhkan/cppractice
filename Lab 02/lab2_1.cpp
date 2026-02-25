/*
Лабораторная работа №2, задание 1
Программисты: Гусев М. С., Патрушев А. В., Трубицын С. А.
Дата и время получения задания: 19.02.2026 09:55
Дата и время сдачи задания: 24.02.2026 11:40
*/

#include <iostream>

int main()
{
	int cnt; // Количество чисел для ввода
	std::cout << "Введите количество чисел для ввода: ";
	std::cin >> cnt;

	// Ввод чисел в массив
	int spisok[cnt];
	for (int i = 0; i < cnt; i++)
	{
		std::cout << "Введите " << i + 1 << " число: ";
		std::cin >> spisok[i];
	}

	// Вывод исходного списка чисел
	std::cout << "Введенный список: ";
	for (int i = 0; i < cnt; i++)
	{
		std::cout << spisok[i] << " ";
	}

	// Поиск числа в котором все цифры расположены в строго возрастающем порядке
	bool flag = false; // Флаг для обозначения найденного числа
	for (int i = 0; i < cnt; i++)
	{
		if (flag == false)
		{
			int temp = spisok[i];
			if (temp < 0)
			{
				temp = -temp;
			}

			if (temp > 9)
			{
				bool error = false;
				while (temp > 9 and error == false)
				{
					if ((temp / 10 % 10) < (temp % 10))
					{
						temp = temp / 10;
						if (temp < 10)
						{
							flag = true;
						}
					}
					else
					{
						error = true;
					}
				}
			}

			// Вывод подходящего числа, если оно найдено
			if (flag == true)
			{
				std::cout << "\nНайденное число: " << spisok[i];
			}
		}
	}

	std::cout << std::endl;
	return 0;
}