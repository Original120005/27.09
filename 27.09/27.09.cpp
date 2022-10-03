#include <iostream>
using namespace std;

struct Element {
	char data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;

public:
	List();
	~List();

	void Add(char data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
	char GetAmount(char& symbol);
	char AddSymbol(char& symbol, int pos);
	char DelSymbol(int pos);

};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

void List::Add(char data)
{
	Element* temp = new Element;

	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}

void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	cout << "\n\n";
}

char List::GetAmount(char& symbol) {
	Element* temp = Head;

	cout << "Введите символ: ";
	cin >> symbol;

	int i = 1, count = 0;
	while (temp != 0) {
		if (temp->data == symbol) {
			break;
		}
		temp = temp->Next;
		i++;
	}
	if (i == 18) {
		cout << "Символ не найден " << symbol << endl;
		return 0;
	}
	cout << "Индекс = " << i << endl;
	return i;
}

char List::AddSymbol(char& symbol, int pos) {
	Element* temp = Head;

	cout << "Введите сивол и позицию: ";
	cin >> symbol >> pos;

	for (int i = 1; i <= pos; i++) {
		temp = temp->Next;
	}
	temp->data = symbol;

	return temp->data;
}

char List::DelSymbol(int pos) {
	Element* temp = Head;
	cout << "Введите позицию: ";
	cin >> pos;

	for (int i = 1; i <= pos; i++) {
		temp = temp->Next;
	}
	Element* temp2 = temp->Next;
	delete temp;

	while (temp2->data != 0) {
		temp2 = temp2->Next;
	}
	return temp2->data;
}



void main() {
	List lst;

	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";

	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		lst.Add(s[i]);
	}
	lst.Print();

	char answer;
	cout << static_cast<int>(lst.GetAmount(answer));

	lst.AddSymbol(answer, 2);

	lst.DelSymbol(4);

	lst.Print();

}