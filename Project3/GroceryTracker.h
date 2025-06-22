/*header file, this file is responsible for declaring all variables and program logic
* @Author Joshua Dunphy
* 6/18/2024
*/

using namespace std;

#include <string>


#ifndef GROCERY_TRACKER_H  //header guard, this is responsible for checking if GROCERY_TRACKER_H has been defined
#define GROCERY_TRACKER_H  //This defines GROCERY_TRACKER_H

class GroceryTracker {

	




private:
	int itemCount;
	int userInput;
	int menuNumber;
	string itemName;
	bool running;
	char charInput;
public:

	GroceryTracker() {    //default constructor for the initialization of GroceryTracker objects
		itemName = "";
		userInput = 0;
		menuNumber = 0;
		itemCount = 0;

	}




	void getItemFrequency(const string& itemName);
	void listItems();
	void displayMenu();
	void Backup();
	void listHistogram(); 

};







#endif // Ends the headerguard by ending the if statement
