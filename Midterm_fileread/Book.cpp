#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {
	//string ISBN;
	//string title;
	//string author;
	//string category;
	int ID;
	//string readerName;
	int startDate = 0;
	int expirationDate = 0;
}

Book::Book(string isbn, string t, string a, string c) {
	ISBN = isbn;
	title = t;
	author = a;
	category = c;
	//int ID;
	//string readerName;
	int startDate = 0;
	int expirationDate = 0;
}

string Book::getISBN() {
	return ISBN;
}

