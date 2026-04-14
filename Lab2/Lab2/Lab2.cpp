#include <iostream>
#include <windows.h>

using namespace std;
int main() {
	SetConsoleCP(1251);       
	SetConsoleOutputCP(1251);
	int N;
	int muil = 1;
	cout << "Введіть число N: ";
	cin >> N;
	for (int i = 1; i <= N; i++) {
		muil *= i; //Множимо нове число на і
	}
	cout << "Добуток чисел від 1 до " << N << " дорівнює " << muil <<
		endl;

	return 0;
}
