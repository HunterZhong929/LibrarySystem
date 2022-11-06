#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {
	//string ISBN;
	//string title;
	//string author;
	//string category;
	ID = IdAssign++;
	//string readerName;
	int startDate = 0;
	int expirationDate = 0;
}

Book::Book(string isbn, string t, string a, string c) {
	ISBN = isbn;
	title = t;
	author = a;
	category = c;
	ID = IdAssign++;
	//string readerName;
	int startDate = 0;
	int expirationDate = 0;
	//TODO the date will be assigne by the ctime counter function.
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

std::istream& operator>>(std::istream &is, Book &book){
	int id, startDate, expirationDate;
	string isbn, readerName, title, author,category;
	is >>title>>author>>isbn>>category>>readerName>>id>>startDate>>expirationDate;
	book.setTitle(title);
	book.setISBN(isbn);
	book.setAuthor(author);
	book.setReaderName(readerName);
	book.setID(id);
	book.setCategory(category);
	book.setStartDate(startDate);
	book.setExpirationDate(expirationDate);
	return is;

}
