#include <iostream>
#include "Student.h"

#include <vector>
#include <fstream>
using namespace std;

void scanBook(vector<Book>& booklist);
void scanStudent(vector<Student>& studentList);
int Book::IDassign = 0;
int main() {
	vector<Book> bookList;
	vector<Student> studentList;
	//------testing code---------
	//vector<Teacher> teacherList;
	Student test = Student();
	test.setUsername("test");
	test.setPassword("1234");
	
	scanBook(bookList);
	for (int i = 0; i < bookList.size(); i++) {
		//cout << bookList[i].getISBN() << " " << bookList[i].getTitle() << " " << bookList[i].getAuthor() << " " << bookList[i].getCategory() << endl;
		cout<<bookList[i];
	}
	test.borrowBook(1,bookList);
	Book testBook = test.searchBook(bookList,1);
	vector<string> searchArgs;
	searchArgs.push_back("Advanced_Calculus");
	vector<Book> testVector = test.searchBook(bookList,searchArgs);
	scanStudent(studentList);	//scan student will do both teacher(1) and student(0)
	for (int i = 0; i < studentList.size(); i++) {
		cout<<studentList[i];
	}
	//cout << "Please enter your username and password: ";
	//cin >> username >> password;
}

void scanBook(vector<Book>& bookList) {
	int copies;
	ifstream fin("book.txt");
	if (fin.fail()) {
		cerr << "Error opening book file.";
		exit(1);
	}

	Book myBook;
	do {
		fin >> myBook;
		//cout << myBook.getISBN() << endl;
		fin >> copies;
		for (int i = 0; i < copies; i++) {
			bookList.push_back(myBook);
			//cout << myBook.getISBN() << " " << myBook.getTitle() << " " << myBook.getAuthor() << " " << myBook.getCategory() << endl;
		}
	} while (!fin.eof());

	//generates a ID for each book in the booklist
	for (int i = 0; i < bookList.size(); i++) {
		bookList[i].setID(i);
	}

	fin.close();
}

//vector<Student>& studentList, vector<Teacher>& teacherList
void scanStudent(vector<Student>& studentList) {
	bool isTeacher;
	ifstream fin("student.txt");
	if (fin.fail()) {
		cerr << "Error opening student file.";
		exit(1);
	}

	//Teacher myTeacher;
	Student myStudent;
	do {
		fin >> isTeacher;
		fin >> myStudent;
		studentList.push_back(myStudent);
		/*
		if (isTeacher) {
			//fin >> myTeacher;
			//teacherList.push_back(myTeacher);
		}
		else {
			//fin >> myStudent;
			//studentList.push_back(myStudent);
		}
		*/
	} while (!fin.eof());

}

