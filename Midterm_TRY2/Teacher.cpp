#include "Teacher.h"
//#include "Book.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Teacher::Teacher() {

}

void Teacher::setUsername(string input) {
	username = input;
}

void Teacher::setPassword(string input) {
	password = input;
}

string Teacher::getUsername() {
	return username;
}

string Teacher::getPassword() {
	return password;
}

void Teacher::searchBook(vector<Book> bookList) {

}

void Teacher::borrowBook(int id, vector<Book> bookList) {
	//checks if any books this teacher owns is overdue

	for (int i = 0; i < borrowedList.size(); i++) {
		if ( (borrowedList[i].getExpirationDate() - borrowedList[i].getBorrowDate()) > maxBorrowPeriod) {	//NEED TO CHANGE maxBorrowPeriod to something appropriate
			//book is overdue and cannot borrow any new book
			cout << "A book is past it's expiration date." << endl;
			return;
		}
	}

	if (borrowedList.size() >= 10) {
		cout << "You have reached the capacity of 10 books." << endl;
		return;
	}

	for (int i = 0; i < bookList.size(); i++) {
		//checks through the library's books to find the appropriate ID, then checks the readerName to see if this book is not borrwed
		if ( (bookList[i].getID() == id) && (bookList[i].getReaderName() == " ")) {
			bookList[i].setReaderName(username);
			bookList[i].setBorrowDate(clock());
			bookList[i].setExpirationDate(clock() + maxBorrowPeriod);		//NEED TO CHANGE MAXBORROW PERIOD IN .H
			cout << "You have borrowed the book " << bookList[i].getTitle() << " with the ID " << bookList[i].getID() << endl;
			return;
		}
	}

	cout << "The ID " << id << " was not found." << endl;
	//no book is overdue so we can use the parameters to add a new book
	//first check if this book has already been borrowed (see if readername == " ")

}

void Teacher::returnBook(int id, vector<Book> bookList) {

}

//void Student::renewBook()

ostream& operator <<(ostream& output, Student& student) {
	output << student.getUsername() << " " << student.getPassword() << endl;
	return output;
}

istream& operator >>(istream& input, Student& student) {
	string inputName;
	string inputPass;
	input >> inputName >> inputPass;
	student.setUsername(inputName);
	student.setPassword(inputPass);
	return input;
}

/*
void Student::addBook() {
}
void Student::removeBook() {
}
*/
