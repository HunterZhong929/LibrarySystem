#include "Student.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include<algorithm>
using namespace std;
int partition(vector<Book>& array, int low, int high) {
	// TODO
    int i = low;
    int j = high -1;
    Book pivot = array[high];
    do{
    while(array[i]<= pivot && i < high){
        i++;
    }
    while(array[j]>= pivot && j > low){
        j--;
    }
    if(i<j){
        Book tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    }
    while(i<j);
    if(array[i] > pivot){
        Book tmp = array[i];
        array[i] = array[high];
        array[high] = tmp;
    }
    return i;
}

void quickSort(vector<Book>& array, int low, int high) {

    if (low < high) {

        // find the pivot element and move elements such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}
int partitionById(vector<Book>& array, int low, int high) {
	// TODO
    int i = low;
    int j = high -1;
    Book pivot = array[high];
    do{
    while(array[i].getID()<= pivot.getID() && i < high){
        i++;
    }
    while(array[j].getID()>= pivot.getID() && j > low){
        j--;
    }
    if(i<j){
        Book tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    }
    while(i<j);
    if(array[i].getID() > pivot.getID()){
        Book tmp = array[i];
        array[i] = array[high];
        array[high] = tmp;
    }
    return i;
}
void quickSort(vector<Book>& array, int low, int high,bool id) {

    if (low < high) {

        // find the pivot element and move elements such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partitionById(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1,id);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high,id);
    }
}
Student::Student() {
	maxCopies = 5;
	maxBorrowPeriod = 150;//30 days = 150secs

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
/**
 * @brief search a book using only ID, using binary search for the ID, the function will first sort the passed-vector of Books
 * 
 * @param bookList a vector of books
 * @param id 
 * @return Book 
 */
Book Student::searchBook(vector<Book> bookList, int id){
	quickSort(bookList, 0,bookList.size()-1,true);
	//sort(bookList.begin(),bookList.end());
	//TODO sort by id
	//now the list is sorted, do the binary search
	int low = 0;
	int high = bookList.size()-1;
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
void Student::borrowBook(int id, vector<Book>& bookList) {
	//checks if any books this student owns is overdue
	time_t currentTime;
	time(&currentTime);


	for (int i = 0; i < borrowedList.size(); i++) {
		
		if ( (currentTime-borrowedList[i].getBorrowDate()) > maxBorrowPeriod) {	//NEED TO CHANGE maxBorrowPeriod to something appropriate
			//book is overdue and cannot borrow any new book
			cout << "A book is past it's expiration date." << endl;
			return;
		}
	}

	if (borrowedList.size() >  maxCopies ) {
		cout << "You have reached the capacity of 5 books." << endl;
		return;
	}

	for (int i = 0; i < bookList.size(); i++) {
		//checks through the library's books to find the appropriate ID, then checks the readerName to see if this book is not borrwed
		if ( (bookList[i].getID() == id) && !(bookList[i].getIsBorrowed())) {
			bookList[i].setReaderName(username);

			bookList[i].setIsBorrowed(true);
			bookList[i].setBorrowDate(currentTime);
			bookList[i].setExpirationDate(currentTime + maxBorrowPeriod);
			borrowedList.push_back(bookList[i]);		//NEED TO CHANGE MAXBORROW PERIOD IN STUDENT.H
			cout << "You have borrowed the book " << bookList[i].getTitle() << " with the ID " << bookList[i].getID() << endl;
			return;
		}
	}

	cout << "The ID " << id << " was not found." << endl;
	//no book is overdue so we can use the parameters to add a new book
	//first check if this book has already been borrowed (see if readername == " ")

}
/**
 * @brief given an ID, search for the book in the student's borrowed list, if it does not exist, throw error
 * borrowed list should not be null and book should exist in the list, else exceptions are thrown
 * @param id 
 */

void Student::returnBook(int id) {
	int i;
	for(i = 0;i<borrowedList.size();i++){
		if(borrowedList[i].getID()==id){
			borrowedList[i].setReaderName(" ");
			borrowedList[i].setIsBorrowed(false);
			break;
		}
	}
	if(i==borrowedList.size()){
		throw std::runtime_error("You did not borrow this book");
	}
	else{
	cout<<"You have successfuly returned the book "<<borrowedList[i]<<endl;
	borrowedList.erase(borrowedList.begin()+i);
	}
}
/**
 * @brief given an ID, search it in the student's borrowed list, if it is null, throw error
 * 
 * @param id 
 */
void Student::renewBook(int id){
	Book renew;
	bool exist = false;
	for(auto i:borrowedList){
		if(i.getID()==id){
			renew = i;
			exist = true;
			break;
		}
	}
	if(!exist){
		throw runtime_error("you did not borrow this book");
	}
	time_t currentTime;
	time(&currentTime);
	renew.setBorrowDate(currentTime);
	renew.setExpirationDate(renew.getBorrowDate()+maxBorrowPeriod);
	cout<<"You have successfully renewed the borrowed book"<<endl;
	cout<<renew;
	
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
	if(i==library.size()){
		throw std::runtime_error("the book with indicated id does not exist");
	}

	library.erase(library.begin()+i);
	cout<<"You have successfully deleted book with id "<<id<<endl;
	
	//



}

Student::Student(bool isStudent_){
	isStudent = isStudent_;
	maxCopies = 10;
	maxBorrowPeriod = 10; //5sec*50days = 250
}
	
	

