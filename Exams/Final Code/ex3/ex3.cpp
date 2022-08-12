#include "stddef.h"
#include <iostream>
#include <map>
#include <vector>
#include "location.h"

using namespace std;

// Return the total distance in the route defined by place_list,
// using the given place_map.
// Return 0.0 if place_list is empty, or only contains one place string.
// Hints: Sum the distances from each successive pair of place names in
// the place_list, looking up the location for each place from place_map,
// and then using the Location::distance() method to
// calculate the distance between each pair of locations.
// You may assume that the place_map contains a value for each string in the
// place_list.
double calc_route_distance(map<string, Location*> &place_map, vector<string> &place_list) {
  // IMPLEMENT THIS METHOD

  double distance = 0.0;

  if (place_list.empty() || place_list.size() == 1) {
      distance = 0.0;
  }
  else {
      Location *obj;

      for (int i = 0; i < place_list.size(); i++) {

          distance += obj->distance(map[place_list[0], ])

      }
  }






}
