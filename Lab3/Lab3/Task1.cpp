#include <iostream>
#include <windows.h>

using namespace std;

int signOfNumber(int x) {
    int result; 

    if (x < 0) {
        result = -1;
    }
    else if (x == 0) {
        result = 0;
    }
    else {
        result = 1;
    }

    return result;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x;
    cout << "Введіть значення числа х:" << endl;
    cin >> x;
    int result = signOfNumber(x);
    cout << "Резульат виконання програми\n" << result << endl;
	return 0;
}
