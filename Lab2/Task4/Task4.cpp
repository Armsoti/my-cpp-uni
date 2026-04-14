#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть число: ";
    cin >> n;

    if (n < 0) {
        cout << "Число не є паліндромом" << endl;
        return 0;
    }

    int original = n;
    long long reversed = 0;

    while (n > 0) {
        int lastDigit = n % 10;
        reversed = reversed * 10 + lastDigit;
        n /= 10;
    }

    if (original == reversed) {
        cout << "Число є паліндромом" << endl;
    }
    else {
        cout << "Число не є паліндромом" << endl;
    }

    return 0;
}