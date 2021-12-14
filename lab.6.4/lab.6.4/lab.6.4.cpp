#include <iostream>
#include <iomanip>

using namespace std;

void Create(int*& a, const int size, const int Low, const int High) // *a - передаємо як посилання
{
	a = new int[size]; // виділили пам'ять
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1); // ініціалізували
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

int Min(int* a, const int size)//найменший елемент масиву 
{
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 1; i < size - 1; i++)
		if (a[i] > 0)
			S += a[i];
	return S;
}




void Sort(int* a, const int size) // метод обміну (бульбашки)
{
	for (int i = 0; i < size - 1; i++)
	{
		int y = a[i];
		int iy = i;
		for (int j = i + 1; j < size; j++)
		{
			if (y == 0)
			{
				y = a[j];
				iy = j;
			}
				
		}
		a[iy] = a[i];
		a[i] = y;
	}

}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

	int n;
	cout << "n = "; cin >> n;
	int* a;
	int Low = -7;
	int High = 1;

	Create(a, n, Low, High);
	Print(a, n);
	cout << "min = "; cout << Min(a, n) << endl;
	cout << "S = " << Sum(a, n) << endl;
	Sort(a, n);
	Print(a, n);
	return 0;
}