// DO NOT MODIFY THIS FILE!
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "location.h"
using namespace std;
#include "ex3.h"

int main() {
  // Read and execute test cases from stdin
  map<string, Location*> place_map;
  string line;
  while (getline(cin, line)) {
    if (line == "0")
      break;
    stringstream ss(line);
    string place;
    double lat, lon;
    ss >> place >> lat >> lon;
    place_map[place] = new Location(lat, lon);
  }
  vector<string> place_list;
  while (getline(cin, line)) {
    stringstream ss(line);
    string place;
    while(ss >> place) {
      place_list.push_back(place);
      cout << place;
      if (!ss.eof())
        cout << "->";
    }
    cout << endl;
    cout.precision(4);
    cout << fixed << "calc_route_distance() returned " << calc_route_distance(place_map, place_list) << endl;
    place_list.clear();
  }
  return 0;
}
