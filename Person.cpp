#include "Thing.h"
#include "Person.h"
Person::Person(std::string arg_name1,std::string arg_name2, GPS_DD arg_pos)
{
  this->name1 = arg_name1;
  this->name2 = arg_name2;
  this->pos = arg_pos;
}

Person::Person(std::string arg_name1,GPS_DD arg_pos)
{
  this->name1 = arg_name1;
  this->pos = arg_pos;

}


Person::Person()
{
  this->name1 = "";
  this->name2 = "";
  this->pos = GPS_DD {};
}

void
Person::setLocation
(GPS_DD arg_location, std::string arg_time)
{
  this->pos = arg_location;
  this->since_when = arg_time;
}


std::string
Person::getName()
{
  return this->name1 + name2;
}

// function prototype
bool
Person::operator==
(Person& aPerson)
{

  return (this->name1 == aPerson.getName());
  return (this->name2 == aPerson.getName());
  
}

void Person::dump
(void)
{
  std::cout << "[Person] dump-begin" << std::endl;
  std::cout << "name           = " << this->name1 << this->name2 << std::endl;
  std::cout << "[Person] dump-end" << std::endl;

  return;
}

Json::Value
Person::dump2JSON
()
{
  Json::Value result;
  result["Who"] = this->name1 + " " + this-> name2;
 
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}
