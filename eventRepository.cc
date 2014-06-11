/*

The MIT License (MIT)

Copyright (c) 2014 Héctor Medina de la Garza

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include <string>
#include "eventStore.hh"
#include "eventRepository.hh"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "binSer.hh"
#include "bon.hh"
#include <vector>
#include <ctime>
#include <stdexcept>


using std::ofstream;
using std::ifstream;
using std::string;
using std::endl;
using std::cout;
using ser::bon;
using std::vector;

std::string get_selfpath() {
    char buff[1024];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1) {
      buff[len] = '\0';
      return std::string(buff);
    } else {
     /* handle error condition */
    }
}




int evt::eventRepository::saveEvent (evt::eventStore const &event){
  std::string appPath =get_selfpath();
  int pos =  appPath.find_last_of("/");
  int res =  appPath.size() -  appPath.find_last_of("/");

  appPath.erase( pos, res);
  
  std::string file =appPath +"/events/"+event.id;

  ofstream os(file, ofstream::binary | ofstream::app);
   

  if (os){

    bon evBon;
    evBon.add("id",event.id);
    evBon.add("eventType", event.eventType);
    evBon.add("streamType", event.streamType);
    evBon.add("expectedVersion", event.expectedVersion);
    evBon.add("newVersion", event.newVersion);
    evBon.add("eventData", event.eventData);
    vector<char> message = evBon.getBinaryMessage();
    vector<char>::size_type size =    message.size();

    os.write(reinterpret_cast<char*> (&message[0]), size);

    os.close();
  }    
  else{
    cout <<"Error when creating file "<< file << endl;
  }
 
  return 1;
}


std::vector<evt::eventStore>  evt::eventRepository::getEvents (std::string const &id, int from, int to){

  cout << "Rehidratando" << endl;

  std::string appPath =get_selfpath();
  int pos =  appPath.find_last_of("/");
  int res =  appPath.size() -  appPath.find_last_of("/");

  appPath.erase( pos, res);
  
  std::string file =appPath +"/events/"+id;

  ifstream input(file, ofstream::binary);

  if (input){

    input.seekg (0, input.end);
    uint64_t length = input.tellg();
    input.seekg (0, input.beg);     

    char* buffer = new char[length];

    input.read(buffer, length);
    
    input.close();

    std::vector<char> data(buffer, buffer + length);
    vector<eventStore> events;
    uint64_t index=0;
    uint64_t total=1;
    std::time_t start = std::time(NULL);
    while (true)
      {

	bon mbon(data, index);
	if (total >= from && total <= to)
	  {
	    //Version without index file so need to be readed
	    eventStore ev;
	    ev.id = mbon.getString("id") ;
	    ev.eventType =mbon.getString("eventType");;
	    ev.streamType = mbon.getString("streamType");
	    ev.expectedVersion = mbon.getInt32("expectedVersion");
	    ev.newVersion = mbon.getInt32("newVersion");
	    ev.eventData = mbon.getString("eventData");       
	    events.push_back(ev);
	  }

	if (index >= data.size()|| total >= to ) 
	  {

	    break;;
	  }
	++total;

      }

    return events;
    }
  else{
    throw std::domain_error(("Error  while opening the file"+file));
  }
   
}
