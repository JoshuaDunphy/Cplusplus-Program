/* Functions - This program is responsible for defining the functions within the program to ensure proper separation from main.cpp
6/18/2024
@Author Joshua Dunphy
*/



#include <fstream>
#include <string>
#include <iostream>
#include "GroceryTracker.h"
#include <map>
using namespace std;



struct Node {   // this is a structure, it defines and groups the member data for the nodes that form our linked list.
	string item;
	int count;
	Node* next;
	Node(string i, int c = 1) : item(i), count(c), next(nullptr) {} // constructor for the node. it will hold a string and int. The string will represent the item, the int the count of the item.
};


void GroceryTracker::getItemFrequency(const string& itemName) {
	int itemCount = 0;
	string line;  //create string to hold current item
	ifstream file("CS210_Project_Three_Input_File.txt");
	if (file.is_open()) {   //check if the file is open
		while (getline(file, line)) {   //check the file line by line since theres one item per line
			if (line == itemName) {    //check if each line is equal to itemName
				itemCount++;
			}
		}
		file.close();// close the file after opening it



		if (itemCount == 0) {
			cout << "The search returned no results." << endl;

		}
		else {
			cout << "There are " << itemCount << " " << itemName << endl;


		}
	}
	else {
		cout << "Unable to open file." << endl;
	}

}





void GroceryTracker::displayMenu() {
	
	cout << "Welcome to the Corner Grocer Grocer Tracker!" << endl;
	cout << "Press 1 to enter a string and return the number of search results assoicated with it." << endl;
	cout << "Press 2 to print the whole list with numbers that represent the frequency of the items purchased." << endl; 
	cout << "Press 3 to see the same information as a histogram, and view asterisks as the frequency of items purchased." << endl;
	cout << "Press 4 to exit the program." << endl;


}

void GroceryTracker::Backup() {
	//check if the backup file has already been created
	ifstream checkFile("frequency.dat");
	if (checkFile.good()) {
		cout << "frequency.dat already exists. Skipping backup." << endl;
		checkFile.close();
		return;   //if the file already exists, return.
	}
	string item;
	ifstream infile("CS210_Project_Three_Input_File.txt"); //declare infile ifstream object

	ofstream outfile("frequency.dat");       //declare outfile ofstream object

	if (infile.is_open() && outfile.is_open()) {   //ensure both files are open
		while (getline(infile, item)) {         //go through infile line-by-line, hold each line in item string
			outfile << item << endl;   //write each item to outfile, then create a new line
		}

		infile.close();    //close the infile
		outfile.close();  //close the outfile

	}
	else {
		cout << "Unable to open both files." << endl;   //print error message if theres a problem opening the files.
	}



}


void GroceryTracker::listItems() {
	Node* head = nullptr;  //initializes the head node, set originally to point to null.

	string item; //hold the data for the current line
	ifstream file("CS210_Project_Three_Input_File.txt");  //go thorugh file line by line, hold each line in string i

	if (file.is_open()) {
		while (getline(file, item)) { //loops through the file until there are no more lines
			Node* current = head;   //initialize our current node to head
			Node* prev = nullptr;   //initialize our prev node to nullptr
			bool found = false;     //declare found as false. this will be updated later on if a value matches a previous


			while (current != nullptr) {  //while currentnode is not pointing to null (checks if we are at end of list or not)
				if (current->item == item) {   //checks if the item value held in the current node is equal to the item value being read.
					current->count++;          //if the value is found, it increases count value, the int assigned to the node.
					found = true;
					break;      //breaks out of the loop, this will start the original loop back.             
				}
				prev = current;
				current = current->next;

			}
			if (!found) {   //if found is not true, then we need to create a new node for the new item
				Node* newNode = new Node(item);    //create the new node with item as the value
				if (prev == nullptr) {    //if prev is still null(if its the first node) 
					head = newNode;    //then set the head as the newNode
				}
				else {       //have prev point to the new node
					prev->next = newNode;
				}

			}

		}
			Node* current = head;  //reset the currrent node to head so we can begin out print
			while (current != nullptr) {
				cout << current->item << " " << current->count << endl;
				current = current->next;
			}
		}
	// clear to avoid memory leaks
	Node* current = head;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

	

void GroceryTracker::listHistogram() {
	map<string, int> histogram;   //declare map to hold string for item and int for number of asterisks 
	string item; 

	ifstream file("CS210_Project_Three_Input_File.txt");   //create ifstream object

	if (file.is_open()) {
		while (getline(file, item)) {   //get the current line and store in string item, until no 
			histogram[item]++; //search if item is in histogram, if it is it will add one value, if not it will initialize it, then increase to 1.
		}
		file.close(); //close the file

		for (const auto& pair : histogram) {  //for each loop that will print asterisks based on the value that is held per the string in map
			cout << pair.first << " ";
			cout << string(pair.second, '*') << endl;
		}
	}
	else {  //print error message if the file was unable to open.
		cout << "Unable to open file." << endl;
	}
}



