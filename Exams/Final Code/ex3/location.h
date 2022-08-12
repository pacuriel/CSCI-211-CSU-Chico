// DO NOT MODIFY THIS FILE!
#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
using namespace std;

// Stores the latitude and Longitude of a location on the Earth
// Since this class is so small, it does not have a .cpp file
class Location {
  public:
    Location(double latitude, double longitude)
      { m_latitude = latitude; m_longitude = longitude; }

    // Returns the distance from this location to the given location.
    // CALL THIS FROM ex3.cpp, calc_route_distance()
    double distance(Location *location);

  private:
    double m_latitude;
    double m_longitude;
};
#endif
