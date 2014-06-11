#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "binSer.hh"
#include "bon.hh"
#include <stdexcept>
#include <bitset>

using std::endl;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using ser::binSer;
using std::map;

//  std::vector<char> binaryMessage;
//  std::map<std::string,std::vector<char>> keys;

void addItemsTo(const vector<char> source, vector<char> &target)
{
  for (auto i : source)
    {
      target.push_back(i);
    }
}


bool keyExists(const map<std::string,vector<char>> &keys,const  string &key)
{
  return !(keys.find(key) == keys.end());
}

ser::bon::bon()  : keys()
{
}


ser::bon::bon (const std::vector<char> &message, uint64_t &lastMessagePosition ) : keys()
{

  std::vector<std::pair<int,std::vector<char>>>::size_type  index = 0;


    std::vector<std::pair<int,std::vector<char>>> values =  binSer::getIndividualValues(message, lastMessagePosition); //Actualiza la posicion del siguiente mensaje
  
    while (index < values.size())
   {
      //get key

      if (values[index].first != 10)
      	{
	  //keys  have to be strings
  	  throw std::invalid_argument("Found a key not being an string");
  	}

      string key = binSer::deserializeString(values[index].second);
      ++index;
     
      //Save the binary value like that
      std::vector<char> full(binSer::serialize( values[index].first));
      addItemsTo({values[index].second.begin(), values[index].second.end()},full);
      keys[key] = full;

      
      //this one is the version doing casting is inefficient
      //get value
      /*  switch (values[index].first)
      {
      case 1 : {
	add(key,binSer::deserializeInt16({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 2 : {
	add(key,binSer::deserializeInt32({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 3 : {
	add(key,binSer::deserializeInt64({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 4 : {
	add(key,binSer::deserializeUInt16({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 5 : {
	add(key,binSer::deserializeUInt32({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 6 : {
	add(key,binSer::deserializeUInt64({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 7 : {
	add(key,binSer::deserializeBoolean({values[index].second.begin(),values[index].second.end() }));
	break;
      }
      case 10 : {	 
	string value = binSer::deserializeString({values[index].second.begin(),values[index].second.end() });
	add(key,value);
	break;
      }
      default:{
	throw std::domain_error(("Message contains Type that is unknow at "+std::to_string(values[index].first)+" at index " + std::to_string(index)));
      }
      }*/
      ++index;
   }
}



void ser::bon::add (const std::string &key, const uint16_t &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{4};
  addItemsTo(serialized,final);
  keys[key]= final;
}



uint16_t ser::bon::getUInt16 (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");

  if ((keys[key])[0] != 4)
    throw std::domain_error("The key value is not UInt16 Type");

  return  binSer::deserializeUInt16(vector<char>(keys[key].begin()+1, keys[key].end()));
}



void ser::bon::add (const std::string &key, const  int16_t &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{1};
  addItemsTo(serialized,final);
  keys[key]= final;
}



int16_t ser::bon::getInt16 (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");

  if ((keys[key])[0] != 1)
    throw std::domain_error("The key value is not Int16 Type");

  return  binSer::deserializeInt16(vector<char>(keys[key].begin()+1, keys[key].end()));
}




void ser::bon::add (const std::string &key, const uint32_t &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{5};
  addItemsTo(serialized,final);
  keys[key]= final;
}



uint32_t ser::bon::getUInt32 (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");

  if ((keys[key])[0] != 5)
    throw std::domain_error("The key value is not UInt32 Type");

  return  binSer::deserializeUInt32(vector<char>(keys[key].begin()+1, keys[key].end()));
}



void ser::bon::add (const std::string &key, const  int32_t &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{2};
  addItemsTo(serialized,final);
  keys[key]= final;
}



int32_t ser::bon::getInt32 (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");

  if ((keys[key])[0] != 2)
    throw std::domain_error("The key value is not Int32 Type");

  return  binSer::deserializeInt32(vector<char>(keys[key].begin()+1, keys[key].end()));
}








void ser::bon::add (const std::string &key, const uint64_t &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{6};
  addItemsTo(serialized,final);
  keys[key]= final;
}



uint64_t ser::bon::getUInt64 (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");

  if ((keys[key])[0] != 6)
    throw std::domain_error("The key value is not UInt64 Type");

  return  binSer::deserializeUInt64(vector<char>(keys[key].begin()+1, keys[key].end()));
}



void ser::bon::add (const std::string &key, const  int64_t &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{3};
  addItemsTo(serialized,final);
  keys[key]= final;
}



int64_t ser::bon::getInt64 (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");

  if ((keys[key])[0] != 3)
    throw std::domain_error("The key value is not Int64 Type");

  return  binSer::deserializeInt64(vector<char>(keys[key].begin()+1, keys[key].end()));
}


void ser::bon::add(const char*  key, const char* value) {
  add(std::string(key), std::string(value));
}


void ser::bon::add (const std::string &key, const std::string &value)
{

  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{10};
  addItemsTo(serialized,final);
  keys[key]= final;
}

std::string ser::bon::getString (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");
 if ((keys[key])[0] != 10)
    throw std::domain_error("The key value is not String Type");

  return  binSer::deserializeString(vector<char>(keys[key].begin()+1, keys[key].end()));  
}


void  ser::bon::add (const std::string &key, const bool &value)
{
  vector<char> serialized  = binSer::serialize(value);
  vector<char> final{7};
  addItemsTo(serialized,final);
  keys[key]= final;

}


bool ser::bon::getBoolean (const std::string &key)
{
  if (!keyExists(keys,key))
    throw std::invalid_argument("The key does not exist in Bon Object");
 if ((keys[key])[0] != 7)
    throw std::domain_error("The key value is not Boolean Type");

  return  binSer::deserializeBoolean(vector<char>(keys[key].begin()+1, keys[key].end()));  
  
}

std::vector<char> ser::bon::getBinaryMessage()
{
  //message sizestrategy one
  //mark of end concat all the values with keys
  //keys as string then actaul binayrvalue and so on
  //at the end add one byte with value 0 mark as end of message
  //when parsing message will parse all the keys until end mark is found
  std::vector<char> retVal;
  for (std::pair<string, std::vector<char> > item: keys)
    {
      //Add Key
      vector<char> final{10};
      vector<char> keybin = binSer::serialize(item.first);
      addItemsTo(keybin,final);
      addItemsTo(final,retVal);
      //Add Value
      addItemsTo(item.second, retVal);
    }

  retVal.push_back(0);

  return retVal;

}
