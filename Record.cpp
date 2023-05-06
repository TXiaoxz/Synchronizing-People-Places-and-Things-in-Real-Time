
#include "Record.h"

Record::Record(Person _p1, Thing _t, GPS_DD _g, std::string _jt)
{
  this->who1 = _p1;
  this->what = _t;
  this->where = _g;
  this->when = _jt;
}

Record::Record(Person _p1, Person _p2, Thing _t, GPS_DD _g, std::string _jt)
{
  this->who1 = _p1;
  this->who2 = _p2;
  this->what = _t;
  this->where = _g;
  this->when = _jt;
}

Record::Record(Person _p1, Person _p2, Thing _t, Thing _t1, GPS_DD _g, std::string _jt)
{
  this->who1 = _p1;
  this->who2 = _p2;
  this->what = _t;
  this->what1 = _t1;
  this->where = _g;
  this->when = _jt;
}

Record::Record(Person _p1, Person _p2, Person _p3, Thing _t, GPS_DD _g, std::string _jt)
{
  this->who1 = _p1;
  this->who2 = _p2;
  this->who3 = _p3;
  this->what = _t;
  this->where = _g;
  this->when = _jt;
}

Record::Record(Person _p1, Person _p2, Person _p3, Thing _t, Thing _t1, GPS_DD _g, std::string _jt)
{
  this->who1 = _p1;
  this->who2 = _p2;
  this->who3 = _p3;
  this->what = _t;
  this->what1 = _t1; // Fixed the assignment
  this->where = _g;
  this->when = _jt;
}

// Removed the duplicate constructor

Record::Record()
{
}
void
Record::setWho1(Person _p1)
{
  this->who1 = _p1;
}

void
Record::setWho2(Person _p1, Person _p2)
{
  this->who1 = _p1;
  this->who2 = _p2;
}

void
Record::setWho3(Person _p1, Person _p2, Person _p3)
{
  this->who1 = _p1;
  this->who2 = _p2;
  this->who3 = _p3;
}

void
Record::setWhat(Thing _t)
{
  this->what = _t;
}

void
Record::setWhat1(Thing _t,Thing _t1)
{
  this->what = _t;
  this->what1 = _t1;
}


void
Record::setWhere(GPS_DD _g)
{
  this->where = _g;
}

void
Record::setWhen(std::string _jt)
{
  this->when = _jt;
}

Json::Value
Record::dump2JSON()
{
  Json::Value result;
  result["where"] = (this->where).dump2JSON();
  result["when"] = this->when;

  Json::Value whoArray;
  whoArray.append(this->who1.dump2JSON());

  if (this->who2.getName() != "") {
    whoArray.append(this->who2.dump2JSON());
  }

  if (this->who3.getName() != "") {
    whoArray.append(this->who3.dump2JSON());
  }

  result["who"] = whoArray;

  if (this->what.type != "" || this->what1.type != "") {
    Json::Value thingsArray;

    if (this->what.type != "") {
      thingsArray.append(this->what.dump2JSON());
    }

    if (this->what1.type != "") {
      thingsArray.append(this->what1.dump2JSON());
    }

    result["Which thing"] = thingsArray;
  }
  return result;
}