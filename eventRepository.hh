#ifndef eventRepository_h
#define eventRepository_h

#include <string>
#include "eventStore.hh"
#include <vector>

namespace evt
{
class eventRepository {
public:
  eventRepository (){}
  static int saveEvent (eventStore const &event);
  static std::vector<eventStore>  getEvents (std::string const &id, int from, int to);
};

}

#endif
