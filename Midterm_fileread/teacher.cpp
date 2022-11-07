#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Teacher.h"
using namespace std;

class Teacher
{
private:
    string username;
    string password;
    //int maxCopies = 10;
    //int maxBorrowPeriod = 50;
    vector<Book> borrowList;
    vector<Book> BookTitles;
public:
    void searchBook();
    void borrowBook(); 
    
    void returnBook();  //
    string getUsername();
    //

};

void Teacher::borrowBook()
{
  if (maxCopies > 10)
    cout << "You can't borrow any more books" << endl;
  else
    maxCopies++;
}

void Teacher::borrowPeriod()
{
  if (maxBorrowPeriod > 50)
    cout << "You can't borrow the book formore than 50 days" << endl;
  else
    maxBorrowPeriod++;

void Teacher searchBook()
{
  cin >> bookTitle;
    if(BookTitles.count(bookTitle)) 
        cout << "This book exist" << endl;
    else
        std::cout << "This book does not exist" << endl;
}
