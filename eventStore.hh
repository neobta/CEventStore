#ifndef eventStore_h
#define eventStore_h

#include <string>

namespace evt
{

class eventStore{

public:


  eventStore()  {}
  eventStore(std::string i, std::string et, std::string st, std::string ed);
  // : id(i), eventType(et), streamType(st), eventData(ed) {}

 
  std::string id;
  std::string eventType;
  std::string streamType;
  int expectedVersion;
  int newVersion;
  std::string eventData;

};
}
#endif

