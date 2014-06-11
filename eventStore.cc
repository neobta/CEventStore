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
