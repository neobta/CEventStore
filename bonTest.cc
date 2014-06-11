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
#include <string>
#include <cctype>
#include "eventRepository.hh"
#include "binSer.hh"
#include <vector>
#include <bitset>
#include <cassert>
#include "bon.hh"
#include <utility>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using ser::binSer;
using std::vector;
using ser::bon;



void printVector(vector<char> &v)
{
  cout << "*** printin vector" << endl;
  for (auto i : v)
    {
      std::bitset<8> s(i);
      cout << s << endl;
    }
}


void testAddGetUInt16(bon &mybon)
{

  uint16_t val =25;
  string key = "evenUint16";
  mybon.add(key, val);
  uint16_t val2= mybon.getUInt16(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}


void testAddGetInt16(bon &mybon)
{

  int16_t val =-30565;
  string key = "eventInt16";
  mybon.add(key, val);
  int16_t val2= mybon.getInt16(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}


void testAddGetUInt32(bon &mybon)
{

  uint32_t val =3500554667;
  string key = "evenUint32";
  mybon.add(key, val);
  uint32_t val2= mybon.getUInt32(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}


void testAddGetInt32(bon &mybon)
{


  int32_t val =-2147483643;
  string key = "eventInt32";
  mybon.add(key, val);
  int32_t val2= mybon.getInt32(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}



void testAddGetUInt64(bon &mybon)
{

  uint64_t val =   18446744073700000000;
  string key = "evenUint64";
  mybon.add(key, val);
  uint64_t val2= mybon.getUInt64(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}


void testAddGetInt64(bon &mybon)
{ 

  int64_t val =-9223372036850000000;
  string key = "eventInt32";
  mybon.add(key, val);
  int64_t val2= mybon.getInt64(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}



void testAddGetString(bon &mybon)
{

  string val ="this is some extrange value could be realley weird á{éioóúlñÑü";
  mybon.add("eventData", val);
  string val2= mybon.getString("eventData");
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}


void testAddGetBoolean(bon &mybon)
{
  bool val = true;
  string key = "eventBoolean";
  mybon.add(key, val);
  bool val2= mybon.getBoolean(key);
  cout << val << ": "<< val2<<endl;
  assert(val==val2);

}




void testFullSerialization(bon &mybon)
{
  //cout << "Checking full serialization"<< endl;
  //vector<char> message = mybon.getBinaryMessage();
  //
  //printVector(message);

    bon bon2;
    uint16_t val1 = 60534;
  bon2.add("int16",val1);

  int16_t val2 = -30052;
  bon2.add("otroint", val2);

  uint32_t val3 = 3543533456;
  bon2.add("anuint32",val3 );
   int32_t val4 = -2147483643;
  bon2.add("anint32", val4);


  uint64_t val5 = 3543533456;
  bon2.add("anuint64",val5 );
  int64_t val6 = -2147483643;
  bon2.add("anint64", val6);
  
  bon2.add("abool" ,true);
  
  

  bon2.add("aString", "demo demo124");

  vector<char> message = bon2.getBinaryMessage();
  printVector(message);
  cout << "Size : " << message.size() << endl; 
  uint64_t lastPosition;
  std::vector<std::pair<int,std::vector<char>>> result =   binSer::getIndividualValues(message, lastPosition);

  cout << "Total values (keys+values) deserialized : " << result.size() << endl;
  cout << "New message posible at  " << lastPosition << " position " << endl;
  uint64_t lastMessagePosition=0;
  bon bon3(message, lastMessagePosition);
  

  for (auto item:bon2.keys)
    {
      cout << "Key :" << item.first << endl;
       printVector(item.second);
      cout << "Value in bon3 "<< endl;
      printVector(bon3.keys[item.first]);
      assert(item.second == bon3.keys[item.first]);
    }

  bon3.add("aString","123e");
  cout << bon3.getString("aString") << endl;

  vector<char> message2 = bon3.getBinaryMessage();
  ser::addItemsTo(message2,message);

  bon bon4(message, lastMessagePosition);
  assert(lastMessagePosition < message.size());

  for (auto item:bon2.keys)
    {
      cout << "Key :" << item.first << endl;
       printVector(item.second);
      cout << "Value in bon4 "<< endl;
      printVector(bon4.keys[item.first]);
      assert(item.second == bon4.keys[item.first]);
    }

  bon bon5({message.begin()+lastMessagePosition, message.end() },lastMessagePosition);

  for (auto item:bon3.keys)
    {
      cout << "Key :" << item.first << endl;
       printVector(item.second);
      cout << "Value in bon5 "<< endl;
      printVector(bon5.keys[item.first]);
      assert(item.second == bon5.keys[item.first]);
    }


}



int main()
{
  bon mybon;
  testAddGetUInt16(mybon);
  testAddGetInt16(mybon);
  testAddGetUInt32(mybon);
  testAddGetInt32(mybon);
  testAddGetUInt64(mybon);
  testAddGetInt64(mybon);
  testAddGetString(mybon);
  testAddGetBoolean(mybon);
  
  testFullSerialization(mybon);

  return 0;
}
