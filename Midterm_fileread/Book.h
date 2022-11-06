#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
	static int IdAssign;//all the ids will be assigned during runtime
	string ISBN;
	string title;
	string author;
	string category;
	int ID;
	string readerName;
	int startDate;
	int expirationDate;
public:
	Book();
	Book(string isbn, string t, string a, string c);
	string iSBN() const { return ISBN; }
	void setISBN(const string &iSBN) { ISBN = iSBN; }
	string getTitle() const { return title; }
	void setTitle(const string &title_) { title = title_; }
	string getAuthor() const { return author; }
	void setAuthor(const string &author_) { author = author_; }
	string getCategory() const { return category; }
	void setCategory(const string &category_) { category = category_; }
	int iD() const { return ID; }
	void setID(int iD) { ID = iD; }
	string getReaderName() const { return readerName; }
	void setReaderName(const string &readerName_) { readerName = readerName_; }
	int getStartDate() const { return startDate; }
	void setStartDate(int startDate_) { startDate = startDate_; }
	int getExpirationDate() const { return expirationDate; }
	void setExpirationDate(int expirationDate_) { expirationDate = expirationDate_; }
	friend std::ostream &operator<<(std::ostream &os, const Book &rhs);
	friend std::istream &operator>>(std::istream &is, Book& book);
	//overload >> to print all info
};