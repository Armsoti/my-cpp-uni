#include <iostream>

void add(int a, double b)
{
	std::cout << "This is function 1." << std::endl;
	int k = a + b;
	std::cout << "The sum of " << a << " and " << b << " is: " << k << std::endl;
}
void add(double a, int b)
{
	std::cout << "\nThis is function 4." << std::endl;
	int k = a + b;
	std::cout << "The sum of " << a << " and " << b << " is: " << k << std::endl;
}

void add(double a, double b)
{
	std::cout << "\nThis is function 2." << std::endl;
	double k = a + b;
	std::cout << "The sum of " << a << " and " << b << " is: " << k << std::endl;
}

void add(int a, int b, int c)
{
	std::cout << "\nThis is function 3." << std::endl;
	int k = a + b + c;
	std::cout << "The sum of " << a << ", " << b << " and " << c << " is: " << k << std::endl;
}

int main()
{
	add(1.0, 2);
	add(1.5, 2.5);
	add(1, 2, 3);
	add(1, 3.0); //Вправа 2 про помилку неоднозначності
}
