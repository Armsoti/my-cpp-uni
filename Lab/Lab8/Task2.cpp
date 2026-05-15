#include <iostream>
#define MAX 100

void vvod(float array[], int arrsize, char q)
{
	for (int i = 0; i < arrsize; i++)
	{
		std::cout << "Enter element"<< i + 1 << "of" << q << "array: ";
		std::cin >> array[i];
	}
}
void calculatedelta(float a[], float b[], float& delta, const int& n, const int& m)
{
	float A, B, C, D, E, F;
	float sumsina, sumcosa, suma, mullsina, sumtgb, mullcosb, sumsinb, sumb;
	float num, den;

	for (int i = 0; i < n; i++)
	{
		sumsina += a[i] * sin(a[i]);
		mullsina *= a[i] * sin(a[i]);
		sumcosa += a[i] * cos(a[i]);
		suma += a[i];
	}

	for (int i = 0; i < m; i++)
	{
		sumtgb += b[i] * tan(b[i]);
		mullcosb *= b[i] * cos(b[i]);
		sumb += b[i];
		sumsinb += b[i] * sin(b[i]);
	}

	A = suma * sumsina;
	B = mullsina;
	C = suma * sumcosa;
	D = sumb * sumtgb;
	E = mullcosb;
	F = sumb * sumsinb;

	num = A*sin(B)+C;
	den = D*cos(E)+F;

	if (den != 0) 
	{
		delta = num / den;
	}
	
}

int main() 
{
	float a[MAX], b[MAX];
	int n, m;

	std::cout << "Enter the number of a array elements(max 100): ";
	std::cin >> n;
	std::cout << "Enter the number of b elements(max 100): ";
	std::cin >> m;

	vvod(a, n, 'a');
	vvod(b, m, 'b');



}