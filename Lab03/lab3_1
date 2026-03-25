/*
Лабораторная работа №3, задание 3
Программисты: Гусев М. С., Патрушев А. В., Трубицын С. А.
*/

#include <iostream>
#include <cmath>

class Complex
{
	double re, im;

public:
	Complex(double r = 0, double i = 0) : re(r), im(i) {}
	double getReal() const { return re; }
	double getImag() const { return im; }
	double modulus() const { return std::sqrt(re * re + im * im); }

	Complex operator+(const Complex &o) const { return {re + o.re, im + o.im}; }
	Complex operator-(const Complex &o) const { return {re - o.re, im - o.im}; }
	Complex operator*(const Complex &o) const { return {re * o.re - im * o.im, re * o.im + im * o.re}; }
	Complex operator/(const Complex &o) const
	{
		double d = o.re * o.re + o.im * o.im;
		return {(re * o.re + im * o.im) / d, (im * o.re - re * o.im) / d};
	}

	void print() const
	{
		std::cout << re;
		if (im >= 0)
			std::cout << "+" << im << "i";
		else
			std::cout << im << "i";
	}
};

class Point3D
{
	Complex x, y, z;

public:
	Point3D() {}
	Point3D(Complex cx, Complex cy, Complex cz) : x(cx), y(cy), z(cz) {}

	double distToOrigin() const
	{
		double a = x.modulus(), b = y.modulus(), c = z.modulus();
		return std::sqrt(a * a + b * b + c * c);
	}

	double distTo(const Point3D &o) const
	{
		double a = (x - o.x).modulus(), b = (y - o.y).modulus(), c = (z - o.z).modulus();
		return std::sqrt(a * a + b * b + c * c);
	}

	void print() const
	{
		std::cout << "(";
		x.print();
		std::cout << ", ";
		y.print();
		std::cout << ", ";
		z.print();
		std::cout << ")";
	}
};

int main()
{
	const int N = 4;
	Point3D pts[N] = {
		{Complex(1, 2), Complex(3, 0), Complex(0, 1)},
		{Complex(4, 0), Complex(1, 1), Complex(2, 0)},
		{Complex(0, 0), Complex(0, 0), Complex(0, 0)},
		{Complex(2, -1), Complex(0, 3), Complex(1, -2)}};

	std::cout << "=== Точки ===\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << "P" << i + 1 << " = ";
		pts[i].print();
		std::cout << "\n";
	}

	std::cout << "\n=== Расстояния до начала координат ===\n";
	for (int i = 0; i < N; i++)
		std::cout << "|P" << i + 1 << "| = " << pts[i].distToOrigin() << "\n";

	std::cout << "\n=== Расстояния между точками ===\n";
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			std::cout << "d(P" << i + 1 << ", P" << j + 1 << ") = " << pts[i].distTo(pts[j]) << "\n";

	std::cout << "\n=== Арифметика Complex ===\n";
	Complex a(3, 4), b(1, 2);
	std::cout << "a = ";
	a.print();
	std::cout << "  |a| = " << a.modulus() << "\n";
	std::cout << "b = ";
	b.print();
	std::cout << "  |b| = " << b.modulus() << "\n";
	std::cout << "a+b = ";
	(a + b).print();
	std::cout << "\n";
	std::cout << "a-b = ";
	(a - b).print();
	std::cout << "\n";
	std::cout << "a*b = ";
	(a * b).print();
	std::cout << "\n";
	std::cout << "a/b = ";
	(a / b).print();
	std::cout << "\n";
}
