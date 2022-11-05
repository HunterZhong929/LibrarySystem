//teacher.h
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Teacher
{
private:
    string username;
    string password;
    //int maxCopies = 10;
    //int maxBorrowPeriod = 50;
    vector<Book> borrowList;
public:
    void searchBook();
    void borrowBook(); 
    
    void returnBook();  //
    string getUsername();
    //

};
