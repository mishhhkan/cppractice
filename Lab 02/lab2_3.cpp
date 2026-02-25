/*
Лабораторная работа №2, задание 3
Программисты: Гусев М. С., Патрушев А. В., Трубицын С. А.
Дата и время получения задания: 19.02.2026 09:55
Дата и время сдачи задания: 24.02.2026 11:40
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	int n; // Размерность матрицы n×n
	std::cout << "Введите размерность матрицы n: ";
	std::cin >> n;
	int matrix[n][n];

	// Инициализация генератора случайных чисел
	srand(time(NULL));

	// Заполнение матрицы случайными числами от -n до +n
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			matrix[i][j] = (rand() % (2 * n + 1)) - n;
			j = j + 1;
		}
		i = i + 1;
	}
	std::cout << std::endl
			  << "Сгенерированная матрица:" << std::endl;

	i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			std::cout << matrix[i][j];
			if (j < n - 1)
				std::cout << "\t";
			j = j + 1;
		}
		std::cout << std::endl;
		i = i + 1;
	}

	// Вычисление определителя методом Гаусса
	float det = 1.0;
	int sign = 1;
	float mat[n][n];
	i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			mat[i][j] = matrix[i][j];
			j = j + 1;
		}
		i = i + 1;
	}

	int k = 0;
	while (k < n)
	{
		int max_row = k;
		float max_val = mat[k][k];
		if (max_val < 0.0)
		{
			max_val = -max_val;
		}
		int r = k + 1;
		while (r < n)
		{
			float val = mat[r][k];
			if (val < 0.0)
			{
				val = -val;
			}
			if (val > max_val)
			{
				max_val = val;
				max_row = r;
			}
			r = r + 1;
		}
		if (max_val == 0.0)
		{
			det = 0.0;
		}
		else
		{
			if (max_row != k)
			{
				sign = -sign;
				int j = 0;
				while (j < n)
				{
					float temp = mat[k][j];
					mat[k][j] = mat[max_row][j];
					mat[max_row][j] = temp;
					j = j + 1;
				}
			}
			det = det * mat[k][k];
			i = k + 1;
			while (i < n)
			{
				float factor = 0.0;
				if (mat[k][k] != 0.0)
				{
					factor = mat[i][k] / mat[k][k];
				}
				int j = k;
				while (j < n)
				{
					mat[i][j] = mat[i][j] - factor * mat[k][j];
					j = j + 1;
				}
				i = i + 1;
			}
		}
		k = k + 1;
	}

	det = det * sign;
	std::cout << std::endl
			  << "Определитель матрицы: " << det << std::endl;

	return 0;
}
