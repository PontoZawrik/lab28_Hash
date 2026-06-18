#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

struct Book {
	char ID[20];
	char author[50];
	char name[50];
	int year;
	char company[50];
	int pageCount;

	void show() {
		cout << "Регистрационный номер: " << ID << endl
			<< "Автор: " << author << " - Название: \"" << name << '\"' << endl
			<< "Количество страниц: " << pageCount << endl
			<< "Издательство: " << company << " в " << year << "г." << endl
			<< "Возраст: " << 2026 - year << endl;
	}
};

struct hashNode {
	Book info;
	int hash;
	hashNode* next;
};

int hashFunc(const char* name, const int pageCount, int size) {
	int hash = 0;

	for (size_t i = 0; i < strlen(name); i++) {
		hash += name[i];
		hash %= size;
	}
	hash += pageCount;
	hash %= size;

	return hash;
}

void addElem(vector<hashNode*>& arr, Book& book) {
	hashNode* newNode = new hashNode;
	int h = hashFunc(book.name, book.pageCount, arr.size());

	newNode->info = book;
	newNode->hash = h;
	newNode->next = arr[h];
	arr[h] = newNode;
}

void deleteElem(vector<hashNode*>& arr, const char* name, int& pageCount) {
	int h = hashFunc(name, pageCount, arr.size());

	hashNode* curr = arr[h];
	hashNode* prev = NULL;

	while (curr != NULL) {
		if (strcmp(curr->info.name, name) == 0 && curr->info.pageCount == pageCount) {
			if (prev != NULL) {
				prev->next = curr->next;
			}
			else {
				arr[h] = curr->next;
			}

			cout << "Delete: " << curr->info.name << endl;
			delete curr;
			return;
		}

		prev = curr;
		curr = curr->next;
	}
	cout << "Not found." << endl;
}

void modifyElem(vector<hashNode*>& arr, const char* name, int& pageCount, Book book) {
	int h = hashFunc(name, pageCount, arr.size());

	hashNode* curr = arr[h];
	hashNode* prev = NULL;

	while (curr != NULL) {
		if (strcmp(curr->info.name, name) == 0 && curr->info.pageCount == pageCount) {
			if (prev != NULL) {
				prev->next = curr->next;
			}
			else {
				arr[h] = curr->next;
			}
			delete curr;

			addElem(arr, book);
			return;
		}

		prev = curr;
		curr = curr->next;
	}
	cout << "Not found." << endl;
}

void showArr(vector<hashNode*>& arr) {
	cout << "Hash table: \n\n";
	for (size_t i = 0; i < arr.size(); i++) {
		hashNode* curr = arr[i];

		while (curr != NULL) {
			curr->info.show();
			cout << "=====================\n";
			curr = curr->next;
		}
	}
}


int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int size;
	cout << "Введите размер хэша: ";
	cin >> size;

	vector<hashNode*> arr(size);

	int p;
	do {
		cout << "1-Создать элемент\n2-Удалить елемент\n3-Изменить элемент\n4-Отобразить массив\n(-1)-Выход\nВведите выбор: ";
		cin >> p;
		cout << endl;
		cin.ignore();

		switch (p) {
			case 1: {
				Book* book = new Book;

				cout << "Регистрационный номер: ";
				cin.getline(book->ID, 50);
				cout << "Автор: ";
				cin.getline(book->author, 50);
				cout << "Название: ";
				cin.getline(book->name, 50);
				cout << "Издательство: ";
				cin.getline(book->company, 50);
				cout << "Год выпуска: ";
				cin >> book->year;
				cout << "количество страниц: ";
				cin >> book->pageCount;
				cout << endl;

				addElem(arr, *book);
			} break;

			case 2: {
				char name[50];
				int pageCount;

				cout << "Название: ";
				cin.getline(name, 50);
				cout << "Количество страниц: ";
				cin >> pageCount;

				deleteElem(arr, name, pageCount);
			} break;

			case 3: {
				char name[50];
				int pageCount;

				cout << "Название (для поиска): ";
				cin.getline(name, 50);
				cout << "Количество страниц (для поиска): ";
				cin >> pageCount;
				cin.ignore();

				Book* book = new Book;

				cout << "\n\nРегистрационный номер: ";
				cin.getline(book->ID, 50);
				cout << "Автор: ";
				cin.getline(book->author, 50);
				cout << "Название: ";
				cin.getline(book->name, 50);
				cout << "Издательство: ";
				cin.getline(book->company, 50);
				cout << "Год выпуска: ";
				cin >> book->year;
				cout << "количество страниц: ";
				cin >> book->pageCount;
				cout << endl;

				modifyElem(arr, name, pageCount, *book);
			} break;

			case 4: {
				showArr(arr);
			} break;

			case -1: cout << "Exit."; break;
			default: cout << "User invalid." << endl; break;
		}
	} while (p != -1);


	showArr(arr);




	system("pause");
	return 0;
}