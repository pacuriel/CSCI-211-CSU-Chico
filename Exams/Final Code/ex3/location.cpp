// DO NOT MODIFY THIS FILE!
#include "location.h"
#include <math.h>
#include <cmath>
using namespace std;

#define EARTH_RADIUS_KM 6371.0
#define DEG_TO_RAD(deg) (deg * M_PI / 180)

// Returns the distance between two lat/lon pairs on the Earth.
// Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
// Source: https://stackoverflow.com
double calc_distance(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = DEG_TO_RAD(lat1d);
  lon1r = DEG_TO_RAD(lon1d);
  lat2r = DEG_TO_RAD(lat2d);
  lon2r = DEG_TO_RAD(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * EARTH_RADIUS_KM * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

double Location::distance(Location *location) {
  // Returns the distance from this location to the given location.
  double result = 0.0;
  if (location != NULL) {
    result = calc_distance(this->m_latitude, this->m_longitude, location->m_latitude, location->m_longitude);
  }
  return result;
}
