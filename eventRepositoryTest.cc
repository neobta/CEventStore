#include "eventStore.hh"
#include <iostream>
#include <string>
#include <cctype>
#include "eventRepository.hh"
#include "binSer.hh"
#include <vector>
#include <bitset>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using ser::binSer;
using std::vector;
using evt::eventStore;
using evt::eventRepository;

 
//  eventStore(std::string i, std::string et, std::string st, std::string ed) : id(i), eventType(et), streamType(st), eventData(ed) {}

//d164a747-b58c-4389-b446-8be7b11282a6
//26f55337-fa52-42b8-8f9a-e111e3d086d1
//a2d64a17-8632-4cb1-a87f-b92a02eab71d
//14adad96-c0a3-47bc-985c-9189480052c3
//fe1a6358-218a-4f36-bdee-4fbc34f28712
//721836d1-87e4-4f0d-bc83-88e4f0f4d6cd
//c9ee7bd2-b4a0-42e3-a4be-2ac6a71c7bf8
//9921a5f2-3b49-4e7c-8edc-b4f1187aa016


void printEvents(const vector<eventStore> evs)
{
  for (eventStore ev :evs)
    {
      cout << "*********************************" << endl;
      cout << "Event Id " << ev.id << endl;
      cout << "Event Type " << ev.eventType << endl;
      cout << "Event StreamType " << ev.streamType<< endl;
      cout << "Event Data " << ev.eventData << endl;
      cout << "*********************************" << endl;
      cout << endl;
    }
}



int main(){

  string id("9921a5f2-3b49-4e7c-8edc-b4f1187aa016");
  //  eventStore ev1(id, "evento \n tipo", "tipo stream", "{evt: som event type with some weird data includede \r\n}");
  //  eventRepository::saveEvent(ev1);
 
  //  cout << get_selfpath() << endl; 
  // static int saveEvent (eventStore const &event);
  

  /*  for (uint64_t index =0; index <= 1000000; ++index)
    {
      if (index %100 == 0)
	{
	  cout << "total events stored " << index << endl;
	}
      eventStore ev2(id, "Same type", "same stream type ", "{evt:More data thta coudl be weired");
      eventRepository::saveEvent(ev2);
    }

  cout << "saved events " <<endl;
  
  */


  vector<eventStore> evs = eventRepository::getEvents(id,100000,100010);
  cout <<endl<< "Event REhydrated " << (evs.size()) << endl;
    printEvents(evs);
  //  cout<< "Read" << endl;
  // cout << ev2.id << endl;

}
