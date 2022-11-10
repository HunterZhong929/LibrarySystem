#include <iostream>
#pragma once
using namespace std;

class Book {
private:
	string ISBN;
	string title;
	string author;
	string category;
	int ID;
	string readerName;
	bool isBorrowed;
	int borrowDate;				//borrowdate is determined by clock()
	int expirationDate;			//expiration date is 30+borrowdate
public:
	// constructors
	Book();
	Book(string title_, string author_, string categroy_, string ISBN_ );
	Book(string isbn, string TITLE, string AUTHOR, string CATEGORY, int id);
	static int IDassign;	
	//overloaded << and >>
	friend ostream& operator<<(ostream& output, Book& book);
	friend istream& operator>>(istream& input, Book& book);
	friend bool operator<(const Book& book1,const Book& book2);
	bool getIsBorrowed() const { return isBorrowed; }
	void setIsBorrowed(bool isBorrowed_) { isBorrowed = isBorrowed_; }
	string getISBN() const { return ISBN; }
	void setISBN(const string &iSBN) { ISBN = iSBN; }
	string getTitle() const { return title; }
	void setTitle(const string &title_) { title = title_; }
	string getAuthor() const { return author; }
	void setAuthor(const string &author_) { author = author_; }
	string getCategory() const { return category; }
	void setCategory(const string &category_) { category = category_; }
	int getID() const { return ID; }
	void setID(int iD) { ID = iD; }
	string getReaderName() const { return readerName; }
	void setReaderName(const string &readerName_) { readerName = readerName_; }
	int getBorrowDate() const { return borrowDate; }
	void setBorrowDate(int borrowDate_) { borrowDate = borrowDate_; }
	int getExpirationDate() const { return expirationDate; }
	void setExpirationDate(int expirationDate_) { expirationDate = expirationDate_; }
	
	//void operator =(Book& book2);
};