//student.h
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Student
{
private:
    string username;
    string password;
    //int maxCopies = 5;
    //int maxBorrowPeriod = 30;
    vector<Book> borrowList;
public:
    void searchBook();
    void borrowBook(); //borrowed by identifying ID, added to student list
                        //Limitations: if student has overdue copies then cant borrow/ if student has more than max can't borrow
    void returnBook();  //
    string getUsername();
    //

};