#include <iostream>
#include "Student.h"
#include<ctime>
#include<chrono>
#include<thread>
#include <vector>
#include <fstream>
using namespace std;
vector<Book> bookList;
vector<Student> studentList;
bool login(Student& loginStudent);
void scanBook(vector<Book>& booklist);
void scanStudent(vector<Student>& studentList);
int dateCounter();
void printMenu();
int prompt_searchBook(int& idInput, vector<string>& searchArgs);
void prompt_borrowBook();


void printBookList(vector<Book>& booklist);
int Book::IDassign = 0;
time_t startDate;
int main() {
	time(&startDate);
	
	//------testing code---------
	//vector<Teacher> teacherList;
	
	Student test = Student();
	test.setUsername("test");
	test.setPassword("1234");
	time_t t1;
	time(&t1);
	cout<<t1<<endl;
	//this_thread::sleep_for(chrono::milliseconds(5000));
	time_t t2;
	time(&t2);
	cout<<t2<<endl;
	
	//------------------------loading the library----------------------------
	
	scanBook(bookList);

	for (int i = 0; i < bookList.size(); i++) {
		//cout << bookList[i].getISBN() << " " << bookList[i].getTitle() << " " << bookList[i].getAuthor() << " " << bookList[i].getCategory() << endl;
		cout<<bookList[i];
	}
	//test.borrowBook(1,bookList);
	Book testBook = test.searchBook(bookList,1);
	vector<string> searchArgs(4);
	searchArgs.push_back("Advanced_Calculus");
	vector<Book> testVector = test.searchBook(bookList,searchArgs);
	scanStudent(studentList);	//scan student will do both teacher(1) and student(0)
	for (int i = 0; i < studentList.size(); i++) {
		cout<<studentList[i];
	}
	cout<<"The current date: day "<<dateCounter();
	//cout << "Please enter your username and password: ";
	//cin >> username >> password;
	//printMenu();
	Student loginStudent;
	login(loginStudent);
	vector<Book> searchResult;
	//--------------------------main loop-------------------------------
	try{
	while(true){
		printMenu();
		int input;
		int idInput;
		int chooseSearch;
		cin>>input;
		switch(input){
			case 1:
				chooseSearch = prompt_searchBook(idInput,searchArgs);
				if(!chooseSearch){
						Book search = loginStudent.searchBook(bookList,idInput);
						cout<<search;
				}
				else if(chooseSearch){
					searchResult = loginStudent.searchBook(bookList, searchArgs);
					printBookList(searchResult);
					
				}
				break;
			case 2:

				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				exit(0);
		}
		}
	}
	catch(runtime_error e){
		cerr<<e.what()<<endl;
	}

}


int dateCounter(){
	time_t currentTime;
	time(&currentTime);
	return difftime(currentTime,startDate)/5;//return the number of time passed in day;

}
/**
 * @brief function to prompt user input for searching books, 
 * 
 * @param idInput 
 * @param searchArgs 
 * @return int 0 means the user wants to search using ID, 1 means string searches
 */
int prompt_searchBook(int& idInput, vector<string>& searchArgs){
	cout<<"Do you want to search by book ID or by Title, Author, Category and ISBN?"<<endl;
	cout<<"enter I/T to select"<<endl;
	char c;
	cin>>c;
	switch(c){
		case 'I':
			cout<<"input book id:";
			cin>>idInput;
			return 0;
		case 'T':
			cout<<"Enter title:";
			cin>>searchArgs[0];
			cout<<endl;
			cout<<"Enter author:";
			cin>>searchArgs[1];
			cout<<endl;
			cout<<"Enter category:";
			cin>>searchArgs[2];
			cout<<endl;
			cout<<"Enter ISBN: ";
			cin>>searchArgs[3];
			cout<<endl;
			return 1;
		default:
			cout<<"Invalid input"<<endl;
	}	
}
inline void prompt_borrowBook(int& idInput) {
	
}
inline void printBookList(vector<Book>& booklist) {
	for(auto i:bookList){
		cout<<i<<endl;
	}
}
void userInterface(){
	//PRINT MENU
}
void printMenu(){
	cout<<"1--Search Book"<<endl;
	cout<<"2--Borrow Book"<<endl;
	cout<<"3--Return Book"<<endl;
	cout<<"4--Renew Book"<<endl;
	cout<<"0--logout"<<endl;


}
bool login(Student& loginStudent){
	cout<<"Login to the system, please enter username and password"<<endl;
	cout<<"Username: ";
	string userName, password;
	cin>>userName;
	cout<<endl;
	
	bool exist=false;
	for(auto i: studentList){
		if(i.getUsername()==userName){
			loginStudent = i;
			exist = true;
			break;
		}
	}
	if(!exist){
		cout<<"the student with the username "<<userName<<" does not exist!"<<endl;
		return false;
	}
	
	while(true){
		cout<<"password:";
		cin>>password;
		if(password==loginStudent.getPassword()){
			cout<<"successfully logged in"<<endl;
			return true;
		}
		else{
			cout<<"Incorrect password!"<<endl;
		}
	}
	
	//if the entered username is not in the list, ask the user to reenter



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

