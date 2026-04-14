#include <iostream>
#include <windows.h>

using namespace std;

int main() {
  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int N;

    cout << "Введіть кількість елементів (не більше 100): ";
    cin >> N;

    while (N > MAX_SIZE || N <= 0) {
        cout << "Помилка: некоректний розмір N. Спробуйте ще раз:" << endl;
        cin >> N;
    }

    cout << "Введіть " << N << " цілих чисел:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Елемент [" << i << "]: ";
        cin >> arr[i];
    }

    int evenSum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        }
    }
    cout << "\nСума парних елементів: " << evenSum << endl;

    double oddSum = 0;
    int oddCount = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 != 0) {
            oddSum += arr[i];
            oddCount++;
        }
    }

    if (oddCount > 0) {
        double average = oddSum / oddCount;
        cout << "Середнє арифметичне непарних елементів: " << average << endl;
    }
    else {
        cout << "Непарних елементів у масиві не знайдено." << endl;
    }

    return 0;
}