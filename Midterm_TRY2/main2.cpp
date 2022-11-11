#include <iostream>
#include "Student.h"
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
using namespace std;

vector<Book> bookList;
vector<Student> studentList;
void login(Student& user);
void scanBook(vector<Book>& booklist);
void scanStudent(vector<Student>& studentList);
int dateCounter();
void printStudentMenu();
void printTeacherMenu();
int promptSearchBook(int& idInput, vector<string>& searchArgs);
void promptBorrowBook(int& idInput);
void promptReturnBook(int& idInput);
void promptRenewBook(int& idInput);
void promptAddBook(vector<string>& searchArgs);
void promptRemoveBook(int& idInput);
void printBookList(vector<Book>& list);
int Book::IDassign = 0;
time_t Book::startTime;
time_t startDate;



int main() {
	time(&startDate);
    Book::startTime = startDate;
	//------testing code---------
	//vector<Teacher> teacherList;

	Student test = Student();
	test.setUsername("test");
	test.setPassword("1234");
	time_t t1;
	time(&t1);
	cout << t1 << endl;
	//this_thread::sleep_for(chrono::milliseconds(5000));
	time_t startTime;

	time(&startTime);
	
	cout << startTime << endl;
	scanBook(bookList);

	//print book list
	for (int i = 0; i < bookList.size(); i++) {
		//cout << bookList[i].getISBN() << " " << bookList[i].getTitle() << " " << bookList[i].getAuthor() << " " << bookList[i].getCategory() << endl;
		cout << bookList[i];
	}
	//test.borrowBook(1,bookList);
	Book testBook = test.searchBook(bookList, 1);
	vector<string> searchArgs(4);
	searchArgs.push_back("Advanced_Calculus");
	vector<Book> testVector = test.searchBook(bookList, searchArgs);
	scanStudent(studentList);	//scan student will do both teacher(1) and student(0)
	for (int i = 0; i < studentList.size(); i++) {
		cout << studentList[i];
	}
	cout << "The current date: day " << dateCounter();
	

	Student user;
	login(user);
	if (user.getIsStudent()) {
		system("clear");
		printStudentMenu();
	} else {
		system("clear");
		printTeacherMenu();
	}
	
	while (true) {	
		
	
		int input;
		int idInput;
		int chooseSearch;
		vector<Book> searchResult;
		cin >> input;
		try{
		switch (input) {
		case 1:
			chooseSearch = promptSearchBook(idInput, searchArgs); //params are ID input and vector for other search params
			if (!chooseSearch) {
				Book searchResult = user.searchBook(bookList, idInput);
				cout<<searchResult;
			}
			else if (chooseSearch) {
				searchResult = user.searchBook(bookList, searchArgs);
				printBookList(searchResult);
			}
			break;
		case 2:
			promptBorrowBook(idInput);
			user.borrowBook(idInput, bookList);
			break;
		case 3:
			promptReturnBook(idInput);
			user.returnBook(idInput);
			break;
		case 4:
			promptRenewBook(idInput);
			user.renewBook(idInput);
			break;
		case 5:
			promptAddBook(searchArgs);
			bookList.push_back(user.addBook(searchArgs[0], searchArgs[1], searchArgs[2], searchArgs[3]));
			printBookList(bookList);
			break;
		case 6:
			promptRemoveBook(idInput);
			user.removeBook(idInput, bookList);
			printBookList(bookList);
			break;
		case 0:
			cout << "Logging out...";
			exit(1);
			break;
		}
		}

		catch(runtime_error e){
			cout<<e.what()<<endl;
		}
	}
	
	
}

void login(Student& user) {
	cout << "Logging into the Library Management System, please enter your username and password" << endl;
	string username, password;
	bool exist = false;

	while (!exist) {
		cout << "Username: ";
		cin >> username;

		for (auto student : studentList) {
			if (student.getUsername() == username) {
				user = student;
				exist = true;
				break;
			}
		}

		if (!exist) cout << "The student with the username " << username << " does not exist. Please try again" << endl;
	}
	
	while (true) {
		cout << "Password: ";
		cin >> password;
		if (password == user.getPassword()) {
			cout << "Successfully logged in" << endl;
			break;
		} else {
			cout << "Incorrect password. Please try again" << endl;
		}
	}
}

int dateCounter() {
	time_t currentTime;
	time(&currentTime);
	return difftime(currentTime, startDate) / 5;//return the number of time passed in day;
}

void printStudentMenu() {
	cout << "-----------------------------------------------------------------" << endl;
	cout << "-\t\t\tWelcome to My Library!\t\t\t-" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "\nWelcome back, Student" << endl;
	cout << "\nPlease choose:" << endl;
	cout << "\t1 -- Search Book" << endl;
	cout << "\t2 -- Borrow Book" << endl;
	cout << "\t3 -- Return Book" << endl;
	cout << "\t4 -- Renew Book" << endl;
	cout << "\t0 -- Log Out\n" << endl;
}

void printTeacherMenu() {
	cout << "-----------------------------------------------------------------" << endl;
	cout << "-\t\t\tWelcome to My Library!\t\t\t-" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "\nWelcome back, Teacher" << endl;
	cout << "\nPlease choose:" << endl;
	cout << "\t1 -- Search Book" << endl;
	cout << "\t2 -- Borrow Book" << endl;
	cout << "\t3 -- Return Book" << endl;
	cout << "\t4 -- Renew Book" << endl;
	cout << "\t5 -- Request a new book copy" << endl;
	cout << "\t6 -- Delete an existing copy" << endl;
	cout << "\t0 -- Log Out\n" << endl;
}

void printBookList(vector<Book>& list) {
	cout << "The list of books fitting the search conditions is displayed below:" << endl;
	for(auto i:list){
		cout<<i;
	}
}

/**
 * @brief function to prompt user input for searching books,
 *
 * @param idInput
 * @param searchArgs
 * @return int 0 means the user wants to search using ID, 1 means string searches
 */

int promptSearchBook(int& idInput, vector<string>& searchArgs) {
	cout << "Do you want to search by book ID or by Title, Author, Category and ISBN?" << endl;
	cout << "enter I/T to select" << endl;
	char c;
	cin >> c;

	switch (c) {
	case 'I':
		cout << "Enter book ID: ";
		cin >> idInput;
		return 0;
	case 'T':
		cout << "Enter title: ";
		cin >> searchArgs[0];
		cout << "Enter author: ";
		cin >> searchArgs[1];
		cout << "Enter category: ";
		cin >> searchArgs[2];
		cout << "Enter ISBN: ";
		cin >> searchArgs[3];
		return 1;
	default:
		cout << "Invalid input" << endl;
	}
}

void promptBorrowBook(int& idInput) {
	cout << "Enter the ID of the book you wish to borrow: ";
	cin >> idInput;
}

void promptReturnBook(int& idInput) {
	cout << "Enter the ID of the book you wish to return: ";
	cin >> idInput;
}

void promptRenewBook(int& idInput) {
	cout << "Enter the ID of the book you wish to renew: ";
	cin >> idInput;
}

void promptAddBook(vector<string>& searchArgs) {
	cout << "Enter the Title, Author, Category and ISBN of the book you want to add to the library" << endl;

	cout << "Enter title: ";
	cin >> searchArgs[0];
	cout << "Enter author: ";
	cin >> searchArgs[1];
	cout << "Enter category: ";
	cin >> searchArgs[2];
	cout << "Enter ISBN: ";
	cin >> searchArgs[3];
}

void promptRemoveBook(int& idInput) {
	cout << "Enter the ID of the book you want to remove from the library: ";
	cin >> idInput;
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
			myBook.setID();
			bookList.push_back(myBook);
			
			//cout << myBook.getISBN() << " " << myBook.getTitle() << " " << myBook.getAuthor() << " " << myBook.getCategory() << endl;
		}
	} while (!fin.eof());

	//generates a ID for each book in the booklist
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
		if (isTeacher) {
		    fin >> myStudent;
		//	//teacherList.push_back(myTeacher);
            myStudent.setIsStudent(false);
            studentList.push_back(myStudent);
		}
		else {
			fin >> myStudent;
			studentList.push_back(myStudent);
        }
	} while (!fin.eof());
}