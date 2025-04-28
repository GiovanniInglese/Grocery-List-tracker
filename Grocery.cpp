/*Giovanni Inglese
* 10/16/24
* Dr. Powell
* CS 210
*/


#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class itemMap {  //Creates a class for an item map to map the name of the item and item frequency
private:
	map<string, int>itemFrequency;
	string newDataFile;   // creates a new string for the data file anme 

public:
	itemMap() { //Creates an instance of the class and defines new data file with the frequency.dat
		newDataFile = "frequency.dat"; // initializes the constructor with the name of the data file
	}
	void readInputFile(const string& filePath) {  //Function read the given input file and counts the otems frequency
		ifstream inFS(filePath); //
		string item;
		if (inFS.is_open()) {
			while (getline(inFS, item)) { // goes through the file until there is no line left
				itemFrequency[item]++; // counts the number of each item and places its value with the name of the item

			}
			inFS.close(); // closes the file

		}
		else {
			cout << "Error opening file" << endl;

		}
	}
	void saveData() { //creates funtion for saving the data to the new file
		ofstream outFS;  //creates variable for new file output stream
		outFS.open(newDataFile);// opens the data file
		if (outFS.is_open()) {
			for (const auto& pair : itemFrequency) { // uses the pair function to read the name of the item and the quantity of the map
				outFS << pair.first << " " << pair.second << endl; // outputs the name of the item and its quantity

			}
			outFS.close();  //closes the file
			cout << "The Data has been saved" << endl;


		}
		else {
			cout << "Error saving data" << endl;
		}



	}
	void itemfrequency() {  //creates function for printing the items name and frequency
		for (const auto& pair : itemFrequency) {  // uses the pair container because theres 2 data types and gets them from the itemFrequency map
			cout << pair.first << " " << pair.second << endl;  // prints the item name and frequency

		}
	}
	void printHistogram() {
		for (const auto& pair : itemFrequency) {
			cout << pair.first << " ";
			for (int i = 0; i < pair.second; i++) {
				cout << "*";


			}
			cout << endl;

		}
	}
	void menuLoop() { // creates function for options menu
		string input;
		int option;

		do{  //loops through options menu until the user exits with option 4
		cout << "Option 1: Input item and check frequency" << endl;
		cout << "Option 2: Print list of items and frequencies" << endl;
		cout << "Option 3: Print inventory histogram" << endl;
		cout << "Option 4: Exit Program" << endl;
		cout << endl;
		cout << "Enter your choice" << endl;
		cin >> option;

		// based on the input the switch statments run the methods created in the class
			switch (option) { // returns the user input item with the frequency
			case 1:
				cout << "Enter your Item with capitalization" <<endl;
			
				cin.ignore(); 
				getline(cin, input);
				cout << "Your item's frequency is: " << itemFrequency[input] << endl;
				cout << endl;

				break;
			case 2: // returns the item frequency for all items
				itemfrequency();
				cout << endl;
				break;
			case 3: // returns a histogram for all items and frequencies
				printHistogram();
				cout << endl;

				break;
			case 4: // exits the program
				cout << "Exiting the program." << endl;
				break;


			}


		} while (option != 4);

	}

	

};

int main() {
	itemMap program;  //Creates object of the itemMap class
	string file; // creates variable to implement into the readFile function

	file = "grocery.file.txt";
	program.readInputFile(file);
	program.saveData(); //Saves the data


	
	program.menuLoop();  // Runs program menu loop


}






