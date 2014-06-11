#include "eventStore.hh"
#include <iostream>
#include <string>
#include <cctype>
#include "eventRepository.hh"
#include "binSer.hh"
#include <vector>
#include <bitset>
#include <cassert>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using ser::binSer;
using std::vector;


 
//  eventStore(std::string i, std::string et, std::string st, std::string ed) : id(i), eventType(et), streamType(st), eventData(ed) {}

//d164a747-b58c-4389-b446-8be7b11282a6
//26f55337-fa52-42b8-8f9a-e111e3d086d1
//a2d64a17-8632-4cb1-a87f-b92a02eab71d
//14adad96-c0a3-47bc-985c-9189480052c3
//fe1a6358-218a-4f36-bdee-4fbc34f28712
//721836d1-87e4-4f0d-bc83-88e4f0f4d6cd
//c9ee7bd2-b4a0-42e3-a4be-2ac6a71c7bf8
//9921a5f2-3b49-4e7c-8edc-b4f1187aa016

void printVector(vector<char> &v)
{
  cout << "*** printin vector" << endl;
  for (auto i : v)
    {
      std::bitset<8> s(i);
      cout << s << endl;
    }
}


void testUInt16(bool print)
{
  uint16_t uint16o = 60000;  
  vector<char> ser = binSer::serialize(uint16o);
  uint16_t uint16n = binSer::deserializeUInt16(ser);  
  if (print)
    printVector(ser);
  cout << "Serializing and deserializing uint16  : " << uint16o << " with deserialized value:  "<< uint16n << " Successful? :" << (uint16o==uint16n) << endl; 
  assert (uint16o==uint16n);
}


void testInt16(bool print){
  int16_t int16o = -32500;
  vector<char> ser = binSer::serialize(int16o);
  int16_t int16n = binSer::deserializeInt16(ser);  
  if (print)
    printVector(ser);
  cout << "Serializing and deserializing int16  : " << int16o << " with deserialized value:  "<< int16n << " Successful? :" << (int16o==int16n) << endl; 
  assert(int16o==int16n);
}

void testUInt32(bool print){
  uint32_t valo = 3000000000;
  vector<char> ser = binSer::serialize(valo);
  uint32_t valn = binSer::deserializeUInt32(ser);  
  if (print)
    printVector(ser);
  cout << "Serializing and deserializing uint32  : " << valo << " with deserialized value:  "<< valn << " Successful? :" << (valo==valn) << endl; 
  assert(valo==valn);
}


void testInt32(bool print){
  int32_t valo = -1500500355;
  vector<char> ser = binSer::serialize(valo);
  int32_t valn = binSer::deserializeInt32(ser);  
  if (print)
    printVector(ser);
  cout << "Serializing and deserializing int32  : " << valo << " with deserialized value:  "<< valn << " Successful? :" << (valo==valn) << endl; 
  assert(valo==valn);
}




void testUInt64(bool print){
  uint64_t valo = 18446744073700000000;
  vector<char> ser = binSer::serialize(valo);
  uint64_t valn = binSer::deserializeUInt64(ser);  
  if (print)
    printVector(ser);
  cout << "Serializing and deserializing uint64  : " << valo << " with deserialized value:  "<< valn << " Successful? :" << (valo==valn) << endl; 
  assert(valo==valn);
}


void testInt64(bool print){
  int64_t valo = -9223372036850000000;
  vector<char> ser = binSer::serialize(valo);
  int64_t valn = binSer::deserializeInt64(ser);  
  if (print)
    printVector(ser);
  cout << "Serializing and deserializing int64  : " << valo << " with deserialized value:  "<< valn << " Successful? :" << (valo==valn) << endl; 
  assert(valo==valn);
}









int main(){


  testUInt16(false);
  testInt16(false);
  testUInt32(false);
  testInt32(false);

  testUInt64(false);
  testInt64(false);


  
  bool v = false;  
  vector<char> c1 = binSer::serialize(v);  
  bool x = binSer::deserializeBoolean(c1);
  cout << "boolean is: " << x << endl;

  string str = "{{This is a long exmaple of a string thtat coul be integrate with : puntuation wired like ñ á é í}}";

  cout << str << endl;
  vector<char> cstr = binSer::serialize(str);
 

  string str2 = binSer::deserializeString(cstr);

  cout<< "String deserializada "  << str2 <<endl;
  cout << "Strings are equal " << (str == str2) << endl;
  
  
 

}
