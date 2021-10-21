#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Path {
  public:
    // Double map
    // <start, <end, distance> >
    const string defaultDestination = "StLouis";
    map<string, map<string, int> > vertices;
    // idea: map of estimate straight line distance to StLouis for each location

    void add_vertex(string name, map<string, int>& e) {
      vertices.insert(map<string, map<string, int> >::value_type(name, e));
    }

    void clear_vertices() { vertices.clear(); }


    vector<string> find_best_path(string city1, string city2) {
      // A* search
      // Returns vector that contains the names of each city in best path
      // city2 will usually be StLouis
      vector<string> nodes;
      vector<string> path;
      return path; 
    }
};

void readData(ifstream &data, Path &p) {
  // Read in data from the file
  // Currently file is setup: start end miles
  // Might add separate file? with approximate distance to St Louis rounded to the nearest mile

  while (true) {
    string start, end; // Starting city, ending city
    int cost; // Milelage to get between

    map<string, int> def;
    
    data >> start;
    if (data.eof()) {
      // Exit condition: reach end of file
      return;
    }
    data >> end;
    data >> cost;

    p.add_vertex(start, temp);

    p[start][end] = cost;
  }

}

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
    inFile >> firstCity >> secondCity >> distance;
    
  }
  inFile.close(); //close the file
  
  
  
  
  
  
  
  
  return 0;
}
