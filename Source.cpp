#include <iostream>

using namespace std;

void Shell(double* Arr, int n) { // ������� ���������� �����
	double count;
	int d = n, i, j;
	d = d / 2; 
	while (d > 0) { //� ������� d ����� ������ �� ������ �� ��� ��� ���� � ������� �� ��������� �� 1 ��������
		for (i = 0; i < n - d; i++) {
			j = i;
			while (j >= 0 && Arr[j] > Arr[j + d]) { //������������� ����� �� �������
				count = Arr[j];
				Arr[j] = Arr[j + d];
				Arr[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
	for (i = 0; i < n; i++) {
		cout << Arr[i] << " "; //����� �������
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
		cout << "������� ������ ���������� ����� � �������: ";
		cin >> n;
	}
	cout << "������� " << n << " �����: "; // ������ � ������� ��� ��������
	for (k = 0; k < n; k++) {
		cin >> Arr[k];
	}
	Shell(Arr, n); //��������� ��������� ������
	m = n / 2;
	Vector *v = new Vector[m]; //��� ������������� �������� ������ ������ ��������
	cout << endl << "����������� �������:";
	for (k = 0; k < m; k++) { //���������� �������� ������� � ������ ������ ���������������� �������
		v[k].a = Arr[k];      
		v[k].b = Arr[n - 1 - k];
		cout << " (" << v[k].a << ";" << v[k].b << ") ";
	}
	system("pause");
	return 0;
}