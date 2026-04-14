#include <iostream>
#include <cmath> 
#include <windows.h>

using namespace std;
int numSum(int N) 
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;// Додаємо i до суми
	}

	return sum;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть число: ";
	cin >> N;
	
	int sum = numSum(N);
	cout << "Сума чисел від 1 до " << N << " дорівнює " << sum <<
		endl;
	return 0;
}
