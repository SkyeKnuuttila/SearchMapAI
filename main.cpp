#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <map>

using namespace std;

class Path {
  public:
    // Double map
    // <start, <end, distance> >
    map<string, map<string, int> > vertices;
    map<string, int> estimatedCosts;
    // idea: map of estimate straight line distance to StLouis for each location

    void add_vertex(string name, map<string, int>& e) {
      vertices.insert(map<string, map<string, int> >::value_type(name, e));
    }
    
    void add_estimatedCost(string name, int cost) {
      estimatedCosts.insert(map<string, int>::value_type(name, cost));
    }

    void clear_vertices() { vertices.clear(); }


    vector<string> find_best_path(string city1, string city2) {
      // A* search
      // Returns vector that contains the names of each city in best path
      // city2 will usually be StLouis
      vector<string> path;
      string start;
      string next;
      
      start = city1;
      path.push_back(city1);
      
      while (start != city2) {

        int currentCost = numeric_limits<int>::max();
        for (auto& x: vertices) {

          if(x.first == start) {
            for (auto& y: x.second) {

              int hCost = estimatedCosts.at(y.first);
              int gCost = y.second;

              if (gCost+hCost < currentCost) {
                currentCost = gCost+hCost;
                next = y.first;
              }
            }
          }
        }
        
        path.push_back(next);
        start = next;
      }

      return path; 
    }
};

void readVertices(ifstream &data, Path &p) {
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
      cout << "Data Loaded" << endl;
      return;
    }
    data >> end;
    data >> cost;

    p.add_vertex(start, def);

    p.vertices[start][end] = cost;
  }

}

void readEstimatedCosts(ifstream &data, Path &p) {
  while (true) {
    string city;
    int cost;

    data >> city;
    if (data.eof()) {
      cout << "Estimated Costs Loaded" << endl;
      return;
    }
    data >> cost;

    p.add_estimatedCost(city, cost);
  }
}

int main(int argv, char *argc[]) {
  /* Currently, driver code is set up to find any city to St Louis and return the path
  ** Couple of changes will need if we want the extra credit
  ** Instead of reading in our hCosts from file, will probably implement something to calculate
  ** Take input for what city we are trying to get to
  ** 
  ** Still need graphical display.
  */
  const string defaultDestination = "StLouis";
  string fileName, cityName; //string to hold an entered file name
  
  ifstream verticesFile; // input file 1: start city, end city, cost
  ifstream estimatedCostFile;
  
  Path p;

  cout << "Please enter a data file: " << endl; //prompt user to enter file name
  cin >> fileName; //read in file name

  cout << "Please enter a starting city: " << endl; //prompt user to enter file name
  cin >> cityName; //read in file name

  verticesFile.clear();
  estimatedCostFile.clear();
  
  verticesFile.open(fileName); //open file
  estimatedCostFile.open("costs.txt");
  

  if (!verticesFile) {
    cout << "Failed to open file" << endl; 
    return 1;
  }

  if (!estimatedCostFile) {
    cout << "Can't find costs.txt" << endl;
    return 1;
  }

  readVertices(verticesFile, p);
  readEstimatedCosts(estimatedCostFile, p);
  
  
  verticesFile.close(); //close the file
  estimatedCostFile.close();

  vector<string> path = p.find_best_path(cityName, defaultDestination);

  for (auto& city: path) {
    cout << city << endl;
  }

  
  return 0;
}
