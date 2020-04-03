#include <iostream>
#include <windows.h>
using namespace std;

struct Node {
	int number;
	Node* next;
	Node* last;
};

Node* head;
Node* tail;
Node* ptrLast;

void CreateList(int n) { // создание списка
	int numb;
	cout << ("Введите Числa: ");
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
	for (int i = 0; i < k; i++) { //цикл смещения на К
		x = ptrLast->number;// сохраняем последнее значение
		Node* ptrDelete = NULL; //удаляем последний элемент
		ptrDelete = tail;
		tail = ptrDelete->last;
		tail->next = NULL;
		ptrLast = tail;
		delete ptrDelete;

		Node* sec = NULL;
		Node* ptr = new Node;// добавляем в начало списка элемент с сохраненным значением
		ptr->number = x;
		ptr->last = NULL;
		sec = ptr;
		ptr->next = head;
		head->last = ptr;
		head = ptr;
	}
}

void PrintList() { //Вывод списка
	Node* ptr = NULL;
	if (head == NULL) cout << ("\t!!! СПИСОК ПУСТ !!!\n\n");
	else {
		cout << ("Список: \n\n");
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
	cout << "Введите количество чисел: ";
	cin >> n;
	CreateList(n);
	cout << "Введите К: ";
	cin >> k;
	SmeshList(k);
	PrintList();
	return 0;
}
