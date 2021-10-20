#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argv, char *argc[]) {
	unordered_map<string, > 
	string fileName; //string to hold an entered file name
	cout << "Please enter a data file: " //prompt user to enter file name
	cin >> fileName; //read in file name
	istream inFile; 
	inFile.open(fileName); //open file
	string firstCity; //intitialize variables to add to maps
	string secondCity;
	int distance;
	while(inFile) { //while there is still unread data in the file
		inFile >> firstCity >> secondCity >> distance;
		
	}
	inFile.close(); //close the file
	
	
	
	
	
	
	
	
	return 0;
}
