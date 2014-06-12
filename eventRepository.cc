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
using ser::binSer;

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




int evt::eventRepository::saveEvent (evt::eventStore  &event){
  std::string appPath =get_selfpath();
  int pos =  appPath.find_last_of("/");
  int res =  appPath.size() -  appPath.find_last_of("/");

  appPath.erase( pos, res);
  
  std::string file =appPath +"/events/"+event.id;

  ofstream os(file, ofstream::binary | ofstream::app);
  
  ofstream ixstream ((file+".ix"), ofstream::binary | ofstream::app);

  if (os){


    //New record position
    ifstream input(file, ofstream::binary);
    input.seekg(0,input.end);
    uint64_t ixpos = input.tellg();
    input.close();



    //Get Current max index
    ifstream inputix(file+".ix", ofstream::binary);
    inputix.seekg(0,inputix.end);
    uint64_t ixpost = inputix.tellg();
    inputix.close();
    event.newVersion = (ixpost/8)+1;


    bon evBon;
    evBon.add("id",event.id);
    evBon.add("eventType", event.eventType);
    evBon.add("streamType", event.streamType);
    evBon.add("expectedVersion", event.expectedVersion);
    evBon.add("newVersion", event.newVersion);
    evBon.add("eventData", event.eventData);
    vector<char> message = evBon.getBinaryMessage();
    vector<char>::size_type size =    message.size();


   
    vector<char> ixbin = binSer::serialize(ixpos);

    ixstream.write(reinterpret_cast<char*> (&ixbin[0]),8);

    os.write(reinterpret_cast<char*> (&message[0]), size);
    ixstream.close();
    os.close();
  }    
  else{
    cout <<"Error when creating file "<< file << endl;
  }
 
  return 1;
}


std::vector<evt::eventStore>  evt::eventRepository::getEvents (std::string const &id, int from, int to){

  cout << "Rehidratando desde "<<from << " hasta " <<to << endl;

  std::string appPath =get_selfpath();
  int pos =  appPath.find_last_of("/");
  int res =  appPath.size() -  appPath.find_last_of("/");

  appPath.erase( pos, res);
  
  std::string file =appPath +"/events/"+id;

  ifstream input(file, ofstream::binary);
  ifstream ixstream ((file+".ix"), ofstream::binary);

  if (input && ixstream ){

    ixstream.seekg(8*(from-1)); 
   
    char* buffstart = new char[8];
    ixstream.read(buffstart, 8);
   
    std::vector<char> startbin(buffstart,buffstart+8);
   

    uint64_t start=binSer::deserializeUInt64(startbin);
    
    ixstream.seekg(8*(to));
    char* buffend = new char[8];
    ixstream.read(buffend, 8);
    
    uint64_t end=binSer::deserializeUInt64(std::vector<char>(buffend, buffend+8));
    
    input.seekg (0, input.end);
    uint64_t length = input.tellg();
    input.seekg (start, input.beg);     
    
    char* buffer = new char[end-start];

    input.read(buffer, end-start);
    
    input.close();

    std::vector<char> data(buffer, buffer + (end-start));

    vector<eventStore> events;
    uint64_t index=0;


    while (true)
      {


	bon mbon(data, index);

  
	//Version without index file so need to be readed
	eventStore ev;
	ev.id = mbon.getString("id") ;
	ev.eventType =mbon.getString("eventType");;
	ev.streamType = mbon.getString("streamType");
	ev.expectedVersion = mbon.getUInt64("expectedVersion");
	ev.newVersion = mbon.getUInt64("newVersion");
	ev.eventData = mbon.getString("eventData");       
	events.push_back(ev);
	  

	if (index >= data.size() ) 
	  {

	    break;;
	  }


      }

    return events;
    }
  else{
    throw std::domain_error(("Error  while opening the file"+file));
  }
   
}
