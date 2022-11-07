#include <iostream>
using namespace std;

class Book {
private:
	string ISBN;
	string title;
	string author;
	string category;
	int ID;
	string readerName;
	int borrowDate;				//borrowdate is determined by clock()
	int expirationDate;			//expiration date is 30+borrowdate
public:
	// constructors
	Book();
	Book(string isbn, string TITLE, string AUTHOR, string CATEGORY, int id);
	//sets
	void setISBN(string input);
	void setTitle(string input);
	void setAuthor(string input);
	void setCategory(string input);
	void setID(int input);
	void setReaderName(string input);
	void setBorrowDate(int input);
	void setExpirationDate(int input);
	//gets
	string getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	int getID();
	string getReaderName();
	int getBorrowDate();
	int getExpirationDate();
	//overloaded << and >>
	friend ostream& operator <<(ostream& output, Book& book);
	friend istream& operator >>(istream& input, Book& book);
	//void operator =(Book& book2);
};