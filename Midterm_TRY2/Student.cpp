#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;

Student::Student() {
	maxCopies = 5;
	maxBorrowPeriod = 30;

}

void Student::setUsername(string input) {
	username = input;
}

void Student::setPassword(string input) {
	password = input;
}

string Student::getUsername() {
	return username;
}

string Student::getPassword() {
	return password;
}
void bookList_sort(vector<Book>& bookList){

}
vector<Book> Student::searchBook(vector<Book> bookList, vector<string> searchKey){
	vector<Book> ret;
	for(auto i:bookList){
		if(i.getTitle()== searchKey[0]||i.getAuthor()==searchKey[1]||i.getCategory()==searchKey[2]||i.getISBN()==searchKey[3]){
			ret.push_back(i);
		}
	}
	std::sort(ret.begin(),ret.end());//TODO write our own sorting algorithm for book class
	return ret;
}

Book Student::searchBook(vector<Book> bookList, int id){
	sort(bookList.begin(),bookList.end());
	//now the list is sorted, do the binary search
	int low = 0;
	int high = bookList.size();
	int mid;
	while(low!=high){
	mid = (low+high)/2;
		if(id == bookList[mid].getID()){
			
			break;
		}
		else if(id>bookList[mid].getID()){
			low = mid+1;
		}
		else{
			high = mid -1;
		}
	}
	return bookList[mid];


}
//TODO: modify the code so it works for both teacher and student
void Student::borrowBook(int id, vector<Book> bookList) {
	//checks if any books this student owns is overdue

	for (int i = 0; i < borrowedList.size(); i++) {
		if ( (borrowedList[i].getExpirationDate() - borrowedList[i].getBorrowDate()) > maxBorrowPeriod) {	//NEED TO CHANGE maxBorrowPeriod to something appropriate
			//book is overdue and cannot borrow any new book
			cout << "A book is past it's expiration date." << endl;
			return;
		}
	}

	if (borrowedList.size() >= 5) {
		cout << "You have reached the capacity of 5 books." << endl;
		return;
	}

	for (int i = 0; i < bookList.size(); i++) {
		//checks through the library's books to find the appropriate ID, then checks the readerName to see if this book is not borrwed
		if ( (bookList[i].getID() == id) && (bookList[i].getReaderName() == " ")) {
			bookList[i].setReaderName(username);
			bookList[i].setBorrowDate(clock());
			bookList[i].setExpirationDate(clock() + maxBorrowPeriod);		//NEED TO CHANGE MAXBORROW PERIOD IN STUDENT.H
			cout << "You have borrowed the book " << bookList[i].getTitle() << " with the ID " << bookList[i].getID() << endl;
			return;
		}
	}

	cout << "The ID " << id << " was not found." << endl;
	//no book is overdue so we can use the parameters to add a new book
	//first check if this book has already been borrowed (see if readername == " ")

}

void Student::returnBook(int id) {
	int i;
	for(i = 0;i<borrowedList.size();i++){
		if(borrowedList[i].getID()==id){
			borrowedList[i].setReaderName(" ");
			borrowedList[i].setIsBorrowed(false);
			break;
		}
	}
	borrowedList.erase(borrowedList.begin()+i);

}

void Student::renewBook(int id){
	Book renew = searchBook(borrowedList,id);
	time_t currentTime;
	time(&currentTime);
	renew.setBorrowDate(currentTime);
	renew.setExpirationDate(renew.getBorrowDate()+30000);
	
}

ostream& operator <<(ostream& output, Student& student) {
	output << student.getUsername() << " " << student.getPassword() << endl;
	return output;
}

istream& operator >>(istream& input, Student& student) {
	string inputName;
	string inputPass;
	input >> inputName >> inputPass;
	student.setUsername(inputName);
	student.setPassword(inputPass);
	return input;
}


Book Student::addBook(string title, string author, string category, string ISBN) {
	if(isStudent){
		throw std::invalid_argument("the user is not a teacher");
	}
	return Book(title, author, category, ISBN);

}

void Student::removeBook(int id,vector<Book>& library) {
	if(isStudent){
		throw std::invalid_argument("the user is not a teacher");
	}
	int i;
	for(i = 0;i<library.size();i++){
		if(library[i].getID()==id){
			break;
		}
	}
	library.erase(library.begin()+i);
	//



}

Student::Student(bool isStudent_){
	isStudent = isStudent_;
	maxCopies = 10;
	maxBorrowPeriod = 50;
}
	
	

