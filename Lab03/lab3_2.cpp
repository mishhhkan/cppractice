/*
Лабораторная работа №3, задание 2
Программисты: Гусев М. С., Патрушев А. В., Трубицын С. А.
*/

#include <iostream>
#include <cmath>

struct Point
{
	double x, y;
};

class Triangle
{
	Point A, B, C;
	static double dist(Point p1, Point p2)
	{
		return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	}

public:
	Triangle() : A{0, 0}, B{3, 0}, C{0, 4} {}
	Triangle(double ax, double ay, double bx, double by, double cx, double cy)
		: A{ax, ay}, B{bx, by}, C{cx, cy} {}

	double sideAB() const { return dist(A, B); }
	double sideBC() const { return dist(B, C); }
	double sideCA() const { return dist(C, A); }
	double perimeter() const { return sideAB() + sideBC() + sideCA(); }
	double area() const
	{
		double s = perimeter() / 2, v = s * (s - sideAB()) * (s - sideBC()) * (s - sideCA());
		return v > 0 ? std::sqrt(v) : 0;
	}

	int type() const
	{
		double a = sideAB(), b = sideBC(), c = sideCA(), e = 1e-6;
		if (std::fabs(a - b) < e && std::fabs(b - c) < e)
			return 0;
		double s[3] = {a, b, c};
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2 - i; j++)
				if (s[j] > s[j + 1])
				{
					double t = s[j];
					s[j] = s[j + 1];
					s[j + 1] = t;
				}
		if (std::fabs(s[0] * s[0] + s[1] * s[1] - s[2] * s[2]) < e)
			return 1;
		if (std::fabs(a - b) < e || std::fabs(b - c) < e || std::fabs(a - c) < e)
			return 2;
		return 3;
	}

	const char *typeName() const
	{
		const char *n[] = {"Равносторонний", "Прямоугольный", "Равнобедренный", "Произвольный"};
		return n[type()];
	}

	void print() const
	{
		std::cout << "[" << typeName() << "] S=" << area() << " P=" << perimeter() << "\n";
	}

	Triangle operator+(Point d) const { return {A.x + d.x, A.y + d.y, B.x + d.x, B.y + d.y, C.x + d.x, C.y + d.y}; }
	Triangle operator-(Point d) const { return {A.x - d.x, A.y - d.y, B.x - d.x, B.y - d.y, C.x - d.x, C.y - d.y}; }
	Triangle operator*(double k) const { return {A.x * k, A.y * k, B.x * k, B.y * k, C.x * k, C.y * k}; }
	Triangle operator/(double k) const { return {A.x / k, A.y / k, B.x / k, B.y / k, C.x / k, C.y / k}; }
};

void printGroup(const char *name, Triangle *arr, int n)
{
	if (!n)
		return;
	std::cout << "\n== " << name << " (" << n << " шт.) ==\n";
	int mx = 0, mn = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << "  ";
		arr[i].print();
		if (arr[i].area() > arr[mx].area())
			mx = i;
		if (arr[i].area() < arr[mn].area())
			mn = i;
	}
	std::cout << "  Макс: ";
	arr[mx].print();
	std::cout << "  Мин:  ";
	arr[mn].print();
}

int main()
{
	const int N = 6;
	Triangle t[N] = {
		{0, 0, 3, 0, 0, 4},
		{0, 0, 4, 0, 2, 3.464},
		{0, 0, 6, 0, 3, 4},
		{0, 0, 5, 0, 1, 3},
		{0, 0, 5, 0, 0, 12},
		{0, 0, 8, 0, 4, 3}};

	std::cout << "=== Все треугольники ===\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << i + 1 << ". ";
		t[i].print();
	}

	Triangle gr[4][N];
	int cnt[4] = {};
	for (int i = 0; i < N; i++)
		gr[t[i].type()][cnt[t[i].type()]++] = t[i];

	const char *names[] = {"Равносторонний", "Прямоугольный", "Равнобедренный", "Произвольный"};
	std::cout << "\n=== Статистика по типам ===";
	for (int i = 0; i < 4; i++)
		printGroup(names[i], gr[i], cnt[i]);
}