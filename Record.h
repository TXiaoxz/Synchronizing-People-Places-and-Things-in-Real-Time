
#ifndef _RECORD_H_
#define _RECORD_H_

// Record.h

#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

class Record
{
 private:
  Person who1;
  Person who2;
  Person who3;
  Thing what;
  Thing what1;
  GPS_DD where;
  std::string when;
  
public:
  Record(Person, Thing, GPS_DD, std::string);
  Record(Person, Person, Thing, GPS_DD, std::string);
  Record(Person, Person, Person ,Thing, GPS_DD, std::string);
  Record(Person, Person, Person ,Thing, Thing, GPS_DD, std::string);
  Record(Person, Person, Thing, Thing, GPS_DD, std::string);
  
  Record();
  void setWho1(Person);
  void setWho2(Person,Person);
  void setWho3(Person,Person,Person);
  void setWhat(Thing);
  void setWhat1(Thing,Thing);
  void setWhere(GPS_DD);
  void setWhen(std::string);
  Json::Value dump2JSON();
};

#endif  /* _RECORD_H_ */
