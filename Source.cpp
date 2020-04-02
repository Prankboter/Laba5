#include <iostream>

using namespace std;

void Shell(double* Arr, int n) { // Функция сортировки Шелла
	double count;
	int d = n, i, j;
	d = d / 2; 
	while (d > 0) { //С помощью d делим массив на группы до тех пор пока в группах не останется по 1 элементу
		for (i = 0; i < n - d; i++) {
			j = i;
			while (j >= 0 && Arr[j] > Arr[j + d]) { //распределение чисел по группам
				count = Arr[j];
				Arr[j] = Arr[j + d];
				Arr[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
	for (i = 0; i < n; i++) {
		cout << Arr[i] << " "; //вывод массива
	}
}

int main()
{
	setlocale(0, "");
	struct Vector {
		double a;
		double b;
	};
	int n = 1, k, m;
	double* Arr = new double[n];
	while (n % 2 != 0) {
		cout << "Введите четное количество чисел в массиве: ";
		cin >> n;
	}
	cout << "Введите " << n << " чисел: "; // массив с числами для векторов
	for (k = 0; k < n; k++) {
		cin >> Arr[k];
	}
	Shell(Arr, n); //сортируем созданный массив
	m = n / 2;
	Vector *v = new Vector[m]; //для представления векторов создал массив структур
	cout << endl << "Несравнимые вектора:";
	for (k = 0; k < m; k++) { //заполнение векторов числами с разных концов отсортированного массива
		v[k].a = Arr[k];      
		v[k].b = Arr[n - 1 - k];
		cout << " (" << v[k].a << ";" << v[k].b << ") ";
	}
	system("pause");
	return 0;
}