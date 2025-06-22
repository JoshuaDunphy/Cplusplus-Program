/*main - this is the main class. This is where the compiler will execute the program, and is responsible for containing the main method
6/18/2024
@Author Joshua Dunphy
*/


#include "GroceryTracker.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <limits>
using namespace std;







int main() {

	bool running = true;  //boolean flag to program loop
	while (running) {   //loop to wrap program to ensure it runs until it is exited.
		GroceryTracker Tracker; //create object of the GroceryTracker class for an instance of the object.
		Tracker.Backup();   //call the Backup function to backup the data file.
		//first function to display the main menu to prompt user for input
		Tracker.displayMenu();
		int userInput;


		//take the userinput after the displayMenu
		cin >> userInput;
		bool incorrectInput = true;  //boolean flag to continue to ask for userinput if they fail
		while (incorrectInput) {
			try {
				if (userInput != 1 && userInput != 2 && userInput != 3) {
					throw invalid_argument("Please try again. You may only input 1, 2, 3, or 4.");
				}

				incorrectInput = false;
				switch (userInput) { //if the input is correct, we move onto case statements.
				case 1: {
					bool retry = true;  //boolean flag to later determine if user wants to continue
					while (retry) {   //while retry is true it will always loop.
						string itemName;
						cout << "Please enter the item you wish to check." << endl;
						cin.ignore();
						getline(cin, itemName);
						Tracker.getItemFrequency(itemName);  //call the function with itemName argument
						cout << "Would you like to try again?" << endl;
						cout << "Press 1 to try another entry, 2 to go to main menu, q to quit" << endl;
						char charInput;
						cin >> charInput;
						if (charInput == '1') {
							retry = true; //continue the loop!
						}
						else if (charInput == '2') {
							retry = false;  //exit to the main menu
						}
						else if (charInput == 'q' || charInput == 'Q') {
							cout << "Quitting..." << endl;
							exit(0); //quit the program
						}
						else {
							cout << "Invalid input, please enter 1 to retry, 2 to go to main menu, or q to quit." << endl;
						}
					}
					break;
				}
				case 2: {
					string i;
					Tracker.listItems();
					bool inputCheck = false;
					while (!inputCheck) {
						cout << "Please enter 1 to return to the main menu, 2 to list the items again, or q to quit" << endl;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear the input buffer
						cin >> i;
						if (i != "Q" && i != "q" && i != "1" && i != "2") {  //ensure that the user types only valid input
							cout << "Invalid input, you may only type 1, 2, or q." << endl;
							continue;       //re-loop if input is valid
						}
						else if (i == "q" || i == "Q") {
							cout << "Quitting..." << endl;
							exit(0);   //quit program

						}
						else if (i == "1") {
							inputCheck = true;   //return to main menu

						}

						else {
							Tracker.listItems(); //re-list items

						}

					}
				}
					  break;
				case 3: {
					Tracker.listHistogram();
					string i; // string declaration to hold user input
					bool inputCheck = false;

					while (!inputCheck) {
						cout << "Please enter 1 to return to the main menu, 2 to list the histogram again, or q to quit" << endl;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear the input buffer
						cin >> i;
						if (i != "Q" && i != "q" && i != "1" && i != "2") {
							cout << "Invalid input, you may only type 1, 2, or q." << endl;
							continue; //re-loop upon recvieving invalid input
						}
						else if (i == "q" || i == "Q") {
							cout << "Quitting..." << endl;
							exit(0); // quit the program
						}
						else if (i == "1") {
							inputCheck = true; //exit to the main loop
						}
						else {
							Tracker.listHistogram();
						}
					}
					break;
				}
				case 4:
					cout << "Exiting the program..." << endl;
					exit(0);
				}
			}
			catch (const invalid_argument& e) {
				cout << e.what() << endl;  // send the error message to console
				cin.clear();               // clear the error
				cin.ignore(1000, '\n');    // ignore the bad input
				cin >> userInput;          // re-prompt the user

			}
		}

	}
	return 0;
}