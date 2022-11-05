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



std::ostream &operator<<(std::ostream &os, const Book &rhs) {
	os << "ISBN: " << rhs.ISBN
		<< " title: " << rhs.title
		<< " author: " << rhs.author
		<< " category: " << rhs.category
		<< " ID: " << rhs.ID
		<< " readerName: " << rhs.readerName
		<< " startDate: " << rhs.startDate
		<< " expirationDate: " << rhs.expirationDate;
	return os;
}

