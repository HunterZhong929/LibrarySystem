#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;



class Student {
private:
	string username;
	string password;
	bool isStudent = true;
	int maxCopies;
	int maxBorrowPeriod;
	vector<Book> borrowedList;				//holds the id of a book
public:										//search book must also organize the bookList
	Student();
	Student(bool isStudent_);
	vector<Book> searchBook(vector<Book> bookList,vector<string> searchKey);		//inside the searchBook function we will ask the user to input (int)ID, or (strings)ISBN etc.
	Book searchBook(vector<Book> bookList, int id);
	void borrowBook(int id, vector<Book>& bookList);		//will check inside borrowbook if
	void returnBook(int id);
	void renewBook(int id);
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
	Book addBook(string title, string author, string category, string ISBN);
	void removeBook(int id, vector<Book>& library);
	bool getIsStudent() const { return isStudent; }
	void setIsStudent(bool isStudent_) { isStudent = isStudent_;maxBorrowPeriod = 1;maxCopies = 10; }
	void sortBook(vector<Book> bookList);
	friend void quickSort(vector<Book>& bookList, int low, int high);
	friend int partition(vector<Book>& array, int low, int high);
};