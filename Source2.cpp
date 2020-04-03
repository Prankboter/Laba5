#include <iostream>

using namespace std;

struct DoubleList //описание узла списка
{
	int data; //информационное поле
	DoubleList* next; //указатель на следующий элемент
	DoubleList* prev; //указатель на предыдущий элемент
};

DoubleList* head;  //глобальная переменная (указатель на первый элемент списка)

void AddList(int value, int position)
{
	DoubleList* node = new DoubleList; //создание нового элемента
	node->data = value; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
	}
	else
	{
		DoubleList* p = head; // добавление нового элемента на выбранную позицию
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
	if (head == NULL) cout << "\nСписок пуст\n\n";
	else
	{
		DoubleList* a = head;
		for (int i = 0; i < (k+1); i++) { // цикл делает отступ на К элементов
			a = a->prev;
		}
		DoubleList* b = a;
		cout << "\nЭлементы смещенного списка: ";
		do {
			cout << a->data << " "; //Вывод всех элелементов до полного круга
			a = a->next;
		} while (a != b);
		cout << "\n\n";
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int value, position, n, k = -1;
	cout << "Сколько элементов вы хотите добавить в список: ";
	cin >> n;
	cout << "Введите " << n << " чисел: ";
	for (position = 0; position < n; position++) {
		cin >> value;
		AddList(value, position);
	}
	while (k < 0) {
		cout << "Введите число К: ";
		cin >> k;
	}
	PrintList(k,n);
	return 0;
}