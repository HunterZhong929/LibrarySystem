#include <iostream>
#include <fstream>
#include <vector>
#include<ctime>
#include "Book.h"
using namespace std;

//constructor
Book::Book() {
	ISBN = " ";
	title = " ";
	author = " ";
	category = " ";
	ID = IDassign++;
	readerName = " ";
	borrowDate = 0;
	expirationDate = 0;
	isBorrowed = false;
}

Book::Book(string isbn, string t, string a, string c) {
	ISBN = isbn;
	title = t;
	author = a;
	category = c;
	ID = IDassign++;
	//string readerName;
	int startDate = 0;
	int expirationDate = 0;
	isBorrowed = false;
	//TODO the date will be assigne by the ctime counter function.
}


//overloads
//ofstream overload will be used to output things to a file (unused in midterm project)
ostream& operator<<(ostream& output, Book& book) {
	output << book.getISBN() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getCategory() << " " << book.getID() << endl;
	return output;
	//add more
}

//ifstream overload will be used to read in data from a file
istream& operator>>(istream& input, Book& book) {
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
/**
 * @brief for easier sorting of the book class, based on 3.4.1 of project description 
 * 
 * @param book2 
 * @return true 
 * @return false 
 */
bool operator<(const Book& book1,const Book& book2){
	if(book1.getIsBorrowed()>book2.getIsBorrowed()){
		return true;//1 when the book1 is borrowed
	}
	time_t currentTime;
	time(&currentTime);
	if(difftime(book1.getExpirationDate(),currentTime)>difftime(book2.getExpirationDate(),currentTime)){
		return true;//2 rank by which book is closer to expiration date
	}
	if(book1.getTitle().compare(book2.getTitle())<0){
		return false;
	}
	if(book1.getAuthor().compare(book2.getAuthor())<0){
		return false;
	}
	if(book1.getISBN().compare(book2.getISBN())<0){
		return false;
	}
	if(book1.getID()<book2.getID()){
		return false;
	}
	else return false;

}
bool operator>(const Book& book1,const Book& book2) {
	return !(book1<=book2);
}

bool operator<=(const Book& book1, const Book& book2) {
	return ((book1<book2)||(book1==book2));
}

bool operator>=(const Book& book1, const Book& book2) {
	return !(book1<book2);
}


bool operator==(const Book& book1,const Book& book2) {
	
	return (book1.getISBN() == book2.getISBN()&&
	book1.getTitle() == book2.getTitle()&&
	book1.getAuthor() == book2.getAuthor()&&
	book1.getCategory() == book2.getCategory());
}
