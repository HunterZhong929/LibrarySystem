#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
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
	string getISBN();
	string getTitle();
	string getAuthor();

	//overload >> to print all info
};