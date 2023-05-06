
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "GPS.h"
#include "JvTime.h"
//#include "Thing.h"

class Person
{
 private:
  std::string name1;
  std::string name2;
  GPS_DD pos;
  std::string since_when;
  
public:
  Person(std::string,GPS_DD);
  Person(std::string, std::string ,GPS_DD);
  Person();
  void setLocation(GPS_DD, std::string);
  bool operator==(Person& aPerson);
  std::string getName();
  GPS_DD getLocation();
  std::string getLocationTime();
  void dump();
  Json::Value dump2JSON();
};

#endif  /* _PERSON_H_ */
