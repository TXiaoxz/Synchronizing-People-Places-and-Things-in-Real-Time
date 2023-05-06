
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

#include "ecs36b_Common.h"

using namespace std;

class GPS_DD
{
 private:
  double latitude;
  double longitude;
  std::string place;
 public:
  explicit GPS_DD();
  explicit GPS_DD(std::string, double, double);
  double getLatitude();
  double getLongitude();
  std::string getPlace();
  double distance(GPS_DD);
  Json::Value dump2JSON();
};

#endif /* _GPS_H_ */
