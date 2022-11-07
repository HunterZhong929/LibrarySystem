#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"
using namespace std;

//constructor
Book::Book() {
	ISBN = " ";
	title = " ";
	author = " ";
	category = " ";
	ID = 0;
	readerName = " ";
	borrowDate = 0;
	expirationDate = 0;
}

Book::Book(string isbn, string TITLE, string AUTHOR, string CATEGORY, int id) {
	ISBN = isbn;
	title = TITLE;
	author = AUTHOR;
	category = CATEGORY;
	ID = id;
	readerName = " ";
	borrowDate = clock();
	expirationDate = clock() + 30000;
}

//getter functions
string Book::getISBN() {
	return ISBN;
}
string Book::getTitle() {
	return title;
}
string Book::getAuthor() {
	return author;
}
string Book::getCategory() {
	return category;
}
int Book::getID() {
	return ID;
}
string Book::getReaderName() {
	return readerName;
}
int Book::getBorrowDate() {
	return borrowDate;
}
int Book::getExpirationDate() {
	return expirationDate;
}

//setter functions
void Book::setISBN(string input) {
	ISBN = input;
}
void Book::setTitle(string input) {
	title = input;
}
void Book::setAuthor(string input) {
	author = input;
}
void Book::setCategory(string input) {
	category = input;
}
void Book::setID(int input) {
	ID = input;
}
void Book::setReaderName(string input) {
	readerName = input;
}
void Book::setBorrowDate(int input) {
	borrowDate = input;
}
void Book::setExpirationDate(int input) {
	expirationDate = input;
}

//overloads
//ofstream overload will be used to output things to a file (unused in midterm project)
ostream& operator <<(ostream& output, Book& book) {
	output << book.getISBN() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getCategory() << " " << book.getID() << endl;
	return output;
	//add more
}

//ifstream overload will be used to read in data from a file
istream& operator >>(istream& input, Book& book) {
	//fin >> book;
	string ISBN;
	string title;
	string author;
	string category;
	//int copies;
	input >> ISBN >> title >> author >> category; //copies
	book.setISBN(ISBN);
	book.setTitle(title);
	book.setAuthor(author);
	book.setCategory(category);
	return input;
	//for (int i = 0; i < copies; i++) {

		//Book myBook(ISBN, title, author, category, 1);
	//}
	//return input;
	//the overload will read in the first 4 data points and main reads in the copy data point and makes a for loop
}

//make an overload = function
/*
void Book::operator =(Book& book2) {
	ISBN = book2.ISBN;
	title = book2.title;
	author = book2.author;
	category = book2.category;

}
*/