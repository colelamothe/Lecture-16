// Acessing files and manipulating data

#include<iostream>
#include<fstream> // loads the file handling library
#include<iomanip>
#include<string>

using namespace std;

int main() {
	// declaring a file stream variable prompts the compiler to look in the project resources for a file of that name and type
	// In order to read from the file it needs to then be opened.

	string fileName;

	cout << "please enter desired file path: " << endl;
	getline(cin, fileName); // using the getline command instead of cin allows us to accomodate file paths with space characters in them as it pulls all characters until receving an return key


	// Variable declaration

	// ifstream inFile("C:\\Users\\100711084\\source\\repos\\Lecture 16\\Lecture 16\\ENGR1200Marks.txt"); // declares a file type variable of name inFile and initializes it at the program path
	ifstream inFile(fileName); // Same as the line above but uses a user provided filepath
	ofstream outFile("C:\\Users\\100711084\\source\\repos\\Lecture 16\\Lecture 16\\ENGR1200MarkReport.txt"); // creates an output variable type in the listed location. Could also use the user input format above.
	

	// When doing a windows file path the '\' character needs to be doubled up as the first one is considered an escape character and breaks the file path.

	// The same above variable declaration can be done as follows:
	/*
	ifstream inFile;
	inFile.open("C:\\Users\\100711084\\source\\repos\\Lecture 16\\Lecture 16");
	*/
	// it is the same but slightly longer

	int currentMark = 0;
	int sum = 0, counter = 0;
	int max, min;

	// If the file is not properly called we will get no compile error since the computer does not care. It will cause a runtime error we need to check for this
	if(inFile.fail()) { // Checks if the file assignment has failed (file could not be found or invalid type)
		cout << "File not found or invalid" << endl;
		system("pause");
		exit(1); // exits the program
	}

	while (!inFile.eof()) { // checks if the varaible is at end of file. if it is not, keep reading the file
		inFile >> currentMark; // same concept as "cin >> variable;"
		sum += currentMark;
		counter++;
		
		// Checks if we are on the first number in the file and uses that to initialize max & min of the data set
		if (counter == 1) {
			max = currentMark;
			min = currentMark;
		}

		// Checks each new number against the max and min and adjust them as needed
		if (currentMark > max) {
			max = currentMark;
		}
		if (currentMark < min) {
			min = currentMark;
		}

	}
	cout << "The average mark for the midterm was: " << setprecision(3) << ((double)sum / counter) << "/30." << endl; // outputs the average mark to 3 decimal places
	cout << "Number of marks used for this average: " << counter << endl; // outputs the number of marks checked
	cout << "Highest Mark: " << max << "\nLowest Mark: " << min << endl;

	//instead of using cout we can also use the output file variable we generated and opened earlier to create a report file with the same information
	// By default if there is no file of that name in that place it will create one, otherwise it will overwrite the existing file.
	outFile << "The average mark for the midterm was: " << setprecision(3) << ((double)sum / counter )<< "/30." << endl; // outputs the average mark to 3 decimal places
	outFile << "Number of marks used for this average: " << counter << endl; // outputs the number of marks checked
	outFile << "Highest Mark: " << max << "\nLowest Mark: " << min << endl;



	inFile.close(); // Closes the file once we are done with it for reasons such as memory conservation and file management 
	outFile.close();

	system("pause");
	return 0;
}