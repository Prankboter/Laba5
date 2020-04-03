#include <iostream>

using namespace std;

struct DoubleList //�������� ���� ������
{
	int data; //�������������� ����
	DoubleList* next; //��������� �� ��������� �������
	DoubleList* prev; //��������� �� ���������� �������
};

DoubleList* head;  //���������� ���������� (��������� �� ������ ������� ������)

void AddList(int value, int position)
{
	DoubleList* node = new DoubleList; //�������� ������ ��������
	node->data = value; //���������� �������� ��������
	if (head == NULL) //���� ������ ����
	{
		node->next = node; //��������� ��������� next
		node->prev = node; //��������� ��������� prev
		head = node; //������������ ������ ������
	}
	else
	{
		DoubleList* p = head; // ���������� ������ �������� �� ��������� �������
		for (int i = position; i > 1; i--) p = p->next;
		if (position == 1) head = node;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
}

void PrintList(int k,int n)
{
	if (head == NULL) cout << "\n������ ����\n\n";
	else
	{
		DoubleList* a = head;
		for (int i = 0; i < (k+1); i++) { // ���� ������ ������ �� � ���������
			a = a->prev;
		}
		DoubleList* b = a;
		cout << "\n�������� ���������� ������: ";
		do {
			cout << a->data << " "; //����� ���� ����������� �� ������� �����
			a = a->next;
		} while (a != b);
		cout << "\n\n";
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int value, position, n, k = -1;
	cout << "������� ��������� �� ������ �������� � ������: ";
	cin >> n;
	cout << "������� " << n << " �����: ";
	for (position = 0; position < n; position++) {
		cin >> value;
		AddList(value, position);
	}
	while (k < 0) {
		cout << "������� ����� �: ";
		cin >> k;
	}
	PrintList(k,n);
	return 0;
}