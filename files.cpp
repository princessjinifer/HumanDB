/* Testing out the input and output of files
 * I started with testing, and it is turning into a full blown program
 * Let's see where this is going to go :)
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#define ASK_FOR_MENU "Return to the menu? (y for menu, n to quit)"

using namespace std;

void readFile();
void writeFile();

char returnToMenu;

string combineNames(string combineFirst, string combineLast) {
	string namesTogether;
	namesTogether = "profiles/";
	namesTogether += combineFirst;
	namesTogether += combineLast;
	return (namesTogether);
}

bool doesFileExist (string Filename) {
	ifstream fileExist(Filename.c_str());
	return fileExist;
}

int main() {
    int mainMenuSelect;

    cout << "\n___________\n" << " Main Menu\n" << "___________\n\n";
    cout << "1) Read an existing profile\n" << "2) Create a new profile\n" << "0) Quit the program\n" << "Enter your choice: ";
    cin >> mainMenuSelect;
	cin.ignore();

	if (mainMenuSelect == 0) {
		exit(0);
	}

    if (mainMenuSelect == 1) {
        readFile();
    }

    if (mainMenuSelect == 2) {
        writeFile();
    }

    return 0;
}

void readFile() {
    string firstName, lastName, fileFirstName, fileLastName, Filename;
	char createProfile;
    int userAge;
	bool fileExists;

    cout << "\nWhat is the first name for the person you are searching for? ";
	getline(cin, firstName);
	cout << "What is the last name? ";
    getline(cin, lastName);

	Filename = combineNames(firstName, lastName);

	fileExists = doesFileExist(Filename);

	while (fileExists == true) {
		ifstream Profiles(Filename.c_str());
    	Profiles >> fileFirstName >> fileLastName >> userAge;
		Profiles.close();

    	cout << "\nFirst Name: " << fileFirstName;
    	cout << "\nLast Name: " << fileLastName;
    	cout << "\nAge: " << userAge << "\n\n";
		break;
	}

	if (fileExists == false) {
		cout << "\nSorry, there is no record for that person.\n";
		cout << "Create a one now? (y/n) ";
//		getline(cin, createProfile);
		cin >> createProfile;
		cin.ignore();

		if (createProfile == 'y') {
			writeFile();
		}

		if (createProfile == 'n') {
//			exit(0);
			cout << "\n";
		}
	}

	cout << ASK_FOR_MENU << "\n";
	cout << ": ";
	cin >> returnToMenu;
	cin.ignore();
	if (returnToMenu == 'y') {
		main ();
	}
	if (returnToMenu == 'n') {
		exit(0);
	}
}

void writeFile() {
    int userAge;
	bool fileExists;
	char overwriteFile;
    string Filename, firstName, lastName;

    cout << "What is the first name? ";
    getline(cin, firstName);
    cout << "What is the last name? ";
    getline(cin, lastName);

	Filename = combineNames(firstName, lastName);
	fileExists = doesFileExist(Filename);

	if (fileExists == false) {
			cout << "How old are they? ";
    		cin >> userAge;

    		ofstream Profiles(Filename.c_str(), ios::out);
    		Profiles << firstName << "\n" << lastName << "\n" << userAge;
			Profiles.close();
	}

	if (fileExists == true) {
		cout << "A file for that person already exists, overwrite it? (y/n) ";
		cin >> overwriteFile;
		cin.ignore();

		if (overwriteFile == 'y') {
			cout << "How old are they? ";
    		cin >> userAge;

    		ofstream Profiles(Filename.c_str(), ios::out);
    		Profiles << firstName << "\n" << lastName << "\n" << userAge;
			Profiles.close();
		}
		if (overwriteFile == 'n') {
			cout << "\n";
		}
	}

	cout << ASK_FOR_MENU << "\n";
	cout << ": ";
	cin >> returnToMenu;
	cin.ignore();
	if (returnToMenu == 'y') {
		main ();
	}
	if (returnToMenu == 'n') {
		exit(0);
	}
}
