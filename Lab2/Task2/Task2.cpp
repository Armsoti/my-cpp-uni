	#include <iostream>
	#include <windows.h>

	using namespace std;
	int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int N;
		int sum = 0;
		cout << "Введіть число N: ";
		cin >> N;
		while (N < 1) 
		{
			cout << "Спробуйте ще раз: ";
			cin >> N;
		}
		for (int i = 1; i <= N; i++) {
			sum += i; // Додаємо i до суми
		}
		cout << "Сума чисел від 1 до " << N << " дорівнює " << sum <<
			endl;

		return 0;
	}