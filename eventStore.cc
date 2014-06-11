#include "eventStore.hh"
#include <iostream>
#include <algorithm>
using std::string;
using std::endl;
using std::cout;
using std::cin;



//mystring.erase( std::remove(mystring.begin(), mystring.end(), '\r'), mystring.end() );


void cleanData(string &str){
  str.erase( std::remove(str.begin(), str.end(), '\r'), str.end() );
  str.erase( std::remove(str.begin(), str.end(), '\n'), str.end() );
}



evt::eventStore::eventStore(std::string i, std::string et, std::string st, std::string ed) : id (i), eventType(et), streamType(st), eventData(ed)
{
  cleanData(id);
  cleanData(eventType);
  cleanData(streamType);
  cleanData(eventData);
}
