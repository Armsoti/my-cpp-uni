#include <iostream>
#define MAX 100

void vvod(float array[], int arrsize)
{
	for (int i = 0; i < arrsize; i++)
	{
		std::cout << "Enter element " << i + 1 << ": ";
		std::cin >> array[i];
	}
}

void calculateStatistics(float array[], int arrsize, float& sum_miv, float& sum_pl, int& k_0)
{
	sum_miv = 0;
	sum_pl = 0;
	k_0 = 0;

	for (int i = 0; i < arrsize; i++)
	{
		if (array[i] < 0)
		{
			sum_miv += array[i];
		}
		else if (array[i] > 0)
		{
			sum_pl += array[i];
		}
		else
		{
			k_0++;
		}
	}
}

int main()
{
	float x[MAX], sum_m, sum_p;
	int k_nul;
	int n;

	do 
	{
		std::cout << "Enter the number of elements(max 100): ";
		std::cin >> n;
	}
	while (n <= 0 || n > MAX);
	
	vvod(x, n);
	calculateStatistics(x, n, sum_m, sum_p, k_nul);
	std::cout << "Sum of negative elements: " << sum_m << std::endl;
	std::cout << "Sum of positive elements: " << sum_p << std::endl;
	std::cout << "Number of zero elements: " << k_nul << std::endl;
}
