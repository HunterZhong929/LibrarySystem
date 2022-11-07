#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;



class Student {
private:
	string username;
	string password;
	int maxCopies = 5;
	int maxBorrowPeriod = 30;
	vector<Book> borrowedList;				//holds the id of a book
public:										//search book must also organize the bookList
	Student();
	void searchBook(vector<Book> bookList);		//inside the searchBook function we will ask the user to input (int)ID, or (strings)ISBN etc.
	void borrowBook(int id, vector<Book> bookList);		//will check inside borrowbook if
	void returnBook(int id, vector<Book> bookList);
	void renewBook(int id, vector<Book> bookList);
	//check expired function?

	//setters
	void setUsername(string input);
	void setPassword(string input);
	//setter for the booklist

	//getters
	string getUsername();
	string getPassword();
	//getter for the booklist
	
	//overload
	friend ostream& operator <<(ostream& output, Student& student);
	friend istream& operator >>(istream& input, Student& student);
};