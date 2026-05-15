#include <iostream>
#include <cmath>
#define MAX 100

void vvod(float array[], int arrsize, char q)
{
    for (int i = 0; i < arrsize; i++)
    {
        std::cout << "Enter element " << i + 1 << " of " << q << " array: ";
        std::cin >> array[i];
    }
}
void calculatedelta(float a[], float b[], float& delta, int n, int m)
{
    float A, B, C, D, E, F;
    float sumsina = 0, sumcosa = 0, suma = 0, mullsina = 1, sumtgb = 0, mullcosb = 1, sumsinb = 0, sumb = 0;
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

    num = A * sin(B) + C;
    den = D * cos(E) + F;

    if (den != 0)
    {
        delta = num / den;
    }
    else
    {
        std::cout << "Error: Division by zero in delta calculation.\n" << std::endl;
    }

}

int main()
{
    float a[MAX], b[MAX], delt = 0;
    int n, m;

    do
    {
        std::cout << "Enter the number of a array elements(max 100): ";
        std::cin >> n;
    } while (n <= 0 || n > MAX);

	do
	{
		std::cout << "Enter the number of b array elements(max 100): ";
		std::cin >> m;
	} while (m <= 0 || m > MAX);

    vvod(a, n, 'a');
    vvod(b, m, 'b');

    calculatedelta(a, b, delt, n, m);
    std::cout << "Delta: " << delt << std::endl;

    return 0;
}