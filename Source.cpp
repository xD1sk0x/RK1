#include <iostream>
#include <string>
#include <algorithm> 

struct Book {
	std::string title;
	std::string author;
	int year;
	int copies;
};

bool compareByTitle(const Book* book1, const Book* book2) {
	return book1->title < book2->title;
}

int main() {
	setlocale(LC_ALL, "rus");
	int numberOfBooks;
	std::cout << "������� ���������� ����: ";
	std::cin >> numberOfBooks;

	Book** books = new Book * [numberOfBooks];

	for (int i = 0; i < numberOfBooks; i++) {
		books[i] = new Book;

		std::cout << "������� �������� ����� #" << i + 1 << ": ";
		std::cin >> books[i]->title;
		std::cout << "������� ������ ����� #" << i + 1 << ": ";
		std::cin >> books[i]->author;
		std::cout << "������� ��� ������� ����� #" << i + 1 << ": ";
		std::cin >> books[i]->year;
		std::cout << "������� ���������� ����� ����� #" << i + 1 << ": ";
		std::cin >> books[i]->copies;
	}

	std::sort(books, books + numberOfBooks, compareByTitle);

	std::cout << "������ ���� � ���������� �������:\n";
	for (int i = 0; i < numberOfBooks; i++) {
		std::cout  << books[i]->title << " - �����: " << books[i]->author
			<< "  ��� �������: " << books[i]->year << "  ���������� �����: " << books[i]->copies << "\n";
	}

	for (int i = 0; i < numberOfBooks; i++) {
		delete books[i];
	}

	delete[] books;

	return 0;
}