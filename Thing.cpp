#include "Thing.h"
#include "Person.h"
void
myPrintLog
(std::string content, std::string fname)
{
  if (fname.size() == 0) return;
  
  FILE *log_f = fopen(fname.c_str(), "a");
  if (log_f == NULL) return;
  
  JvTime *jv_ptr = getNowJvTime();
  std::string *str_ptr = jv_ptr->getTimeString();
  fprintf(log_f, "[%s] %s\n", str_ptr->c_str(), content.c_str());
  delete str_ptr;
  delete jv_ptr;
  fflush(log_f);
  fclose(log_f);
  return;
}

Thing::Thing
(void)
{
  this->type = "";
  this->stuff = "";

}

Thing::Thing
(Person arg_owner)
{
  this->type = "";
  this->stuff = "";
  this->owner = arg_owner;
}


Json::Value
Thing::dump2JSON
()
{
  Json::Value result;
  result["type"] = this-> type;
  result["Name"] = this -> stuff;
 
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}



void Thing::dump
(void)
{
  std::cout << "[Thing] dump-begin" << std::endl;
  std::cout << "model          = " << this->model << std::endl;
  std::cout << "sequence_num   = " << this->sequence_num << std::endl;
  std::cout << "description    = " << this->description << std::endl;
  std::cout << "[Thing] dump-end" << std::endl;
  return;
}
