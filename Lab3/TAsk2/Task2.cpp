#include <iostream>
#include <windows.h>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int N;
    cout << "Введіть бажану кількість елементів масиву" << endl;
    cin >> N;

    while (N > MAX_SIZE || N <= 0) 
    {
        cout << "Помилка! Кількість має бути від 1 до 100." << endl;
        cout << "Спробуйте ще раз:" << endl;
        cin >> N;
    }

    cout << "Введіть " << N << " чисел:" << endl;

    for (int i = 0; i < N; i++) {
        cout << "Введіть " << i+1 << " число:" << endl;
        cin >> arr[i];
    }

    cout << "Введений масив з " << N << " чисел:" << endl;

    for (int i = 0; i < N; i++) {
        cout << arr[i]<< " ";
    }

    bubbleSort(arr, N);

    cout << "\nВідсортований масив з " << N << " чисел:" << endl;

    for (int i = 0; i < N; i++) {
        cout << arr[i]<< " ";
    }

    return 0;
}
    

