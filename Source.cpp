#include <iostream>
#include <windows.h>
using namespace std;

class Node
{
public:
	int number;
	Node* next;
	Node* last;
};

Node* head;
Node* tail;
Node* ptrLast;

void CreateList(int n) { // �������� ������
	int numb;
	cout << ("������� ����a: ");
	for (int i = 0; i < n; i++) {
		cin >> numb;
		Node* ptr = new Node;
		ptr->number = numb;
		ptr->next = NULL;
		tail = ptr;
		if (head == NULL) {
			head = ptr;
			ptrLast = ptr;
			ptr->last = NULL;
		}
		else {
			ptr->last = ptrLast;
			ptrLast->next = ptr;
			ptrLast = ptr;
		}
	}
}

void SmeshList(int k) {
	int x;
	for (int i = 0; i < k; i++) { //���� �������� �� �
		x = ptrLast->number;// ��������� ��������� ��������
		Node* ptrDelete = NULL; //������� ��������� �������
		ptrDelete = tail;
		tail = ptrDelete->last;
		tail->next = NULL;
		ptrLast = tail;
		delete ptrDelete;

		Node* sec = NULL;
		Node* ptr = new Node;// ��������� � ������ ������ ������� � ����������� ���������
		ptr->number = x;
		ptr->last = NULL;
		sec = ptr;
		ptr->next = head;
		head->last = ptr;
		head = ptr;
	}
}

void PrintList() { //����� ������
	Node* ptr = NULL;
	if (head == NULL) cout << ("\t!!! ������ ���� !!!\n\n");
	else {
		cout << ("������: \n\n");
		ptr = head;
		while (1)
		{
			cout << ptr->number << " ";
			if (ptr->next == 0)
				break;
			ptr = ptr->next;
		}
		cout << "\n\n";
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n,k;
	cout << "������� ���������� �����: ";
	cin >> n;
	CreateList(n);
	cout << "������� �: ";
	cin >> k;
	SmeshList(k);
	PrintList();
	return 0;
}