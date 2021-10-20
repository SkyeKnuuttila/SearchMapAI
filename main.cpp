#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

//make a map of city names and path distances
map<string, map<string, int>> paths;

int main(int argv, char *argc[]) {
	string fileName; //string to hold an entered file name
	cout << "Please enter a data file: " //prompt user to enter file name
	cin >> fileName; //read in file name
	istream inFile; 
	inFile.open(fileName); //open file
	string firstCity; //intitialize variables to add to maps
	string secondCity;
	int distance;
	while(inFile) { //while there is still unread data in the file
		//read in 2 cities and add the distance between those 2 cities
		inFile >> firstCity >> secondCity >> distance;
		paths[firstCity][secondCity] = distance;
		//and reverse the cities for easier lookups
		paths[secondCity][firstCity] = distance;
	}
	inFile.close(); //close the file
	
	//prompt the user to enter a city to find the shortest distance between it and St Louis
	cout << "Please enter a city to find the shortest path to St. Louis: ";
	string city;
	cin >> city;
	
	/* Bonus points
	//prompt the user to enter 2 cities to find the shortest distance between them
	cout << "Please enter 2 cities to find the shortest path between them: ";
	string city1;
	string city2;
	cin >> city1 >> city2;
	*/
	
	
	
	
	
	
	return 0;
}
