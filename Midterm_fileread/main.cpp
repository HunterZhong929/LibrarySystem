#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"
#include "Student.h"
using namespace std;

int main() {
	vector<Teacher> teachers;
	vector<Student> students;
	vector<Book> books;

	fileOperation(teachers, students, books);
	//login function here
	//
	//then try printing out the info here
}

void fileOperation(vector<Teacher> t, vector<Student> s, vector<Book> b) {
	//opens the file storing the book information
	istream	fin("book.txt");
	if (fin.fail()) {
		cerr << "Error opening book.txt";
		exit(1);
	}
	//our variables for reading in the book file values
	string ISBN;
	string title;
	string author;
	string category;
	int numCopies;
	do {
		fin >> ISBN >> title >> author >> category >> numCopies;

		for (int i = 0; i < numCopies; i++) {
			Book book(ISBN, title, author, category, numCopies);
			b.push_back(book);
		}

	} while (!fin.eof());
	fin.close();



	//opens the file student.txt which has students and includes teachers as well
	istream fin("student.txt"); 
	if(fin.fail()) {
		cerr << "Error opening student.txt";
		exit(1);
	}
	//our variables for reading in the student file values
	bool isTeacher;
	string username;
	string password;
	do {
		fin >> isTeacher >> username >> password;
		if (isTeacher) {
			Teacher teacher();
			t.push_back(teacher);
		}
		else {
			Student student();
			s.push_back(student);
		}
	} while (!fin.eof());
}

/*
Book::operator >> (input1) {
	cout << "ID, "
	input >> ID;
	cout << "author"
	input >> 
	assign value
}
*/