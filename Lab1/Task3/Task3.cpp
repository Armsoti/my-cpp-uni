#include <iostream>

int main()
{
	double firstNumber = 0.0;
	double secondNumber = 0.0;

	std::cout << "Enter the first number: ";
	while (!(std::cin >> firstNumber))
	{
		std::cout << "Error! Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}

	std::cout << "Enter the second number: ";
	while (!(std::cin >> secondNumber))
	{
		std::cout << "Error! Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}

	const double sum = firstNumber + secondNumber;
	const double sub = firstNumber - secondNumber;
	const double mult = firstNumber * secondNumber;

	std::cout << "sum: " << sum << '\n';
	std::cout << "subtraction: " << sub << '\n';
	std::cout << "multiplication: " << mult << '\n';

	if (secondNumber != 0)
	{
		double division = firstNumber / secondNumber;
		std::cout << "division: " << division << '\n';
	}
	else
	{
		std::cout << "Quotient: Error! Division by zero is not allowed.\n";
	}
	return 0;
}