#ifndef bon_h
#define bon_h

#include <iostream>
#include <string>
#include <vector>
#include "binSer.hh"
#include <map>

namespace ser{


class bon{
public:
  bon (); // has to be implemented

  bon (const std::vector<char> &message,uint64_t &lastMessagePosition);



  void add (const std::string &key, const uint16_t &value);
  uint16_t getUInt16 (const std::string &key);

  void add (const std::string &key, const int16_t &value);
  int16_t getInt16 (const std::string &key);

  void add (const std::string &key, const uint32_t &value);
  uint32_t getUInt32 (const std::string &key);

  void add (const std::string &key, const int32_t &value);
  int32_t getInt32 (const std::string &key);

  void add (const std::string &key, const uint64_t &value);
  uint64_t getUInt64 (const std::string &key);

  void add (const std::string &key, const int64_t &value);
  int64_t getInt64 (const std::string &key);

  void add (const char* key, const char* value);

  void add (const std::string &key, const std::string &value);
  std::string getString (const std::string &key);

  void add (const std::string &key, const bool &value);
  bool getBoolean (const std::string &key);

  std::vector<char> getBinaryMessage();



  std::map<std::string,std::vector<char>> keys;
    

}; // end class

}//end namespace
#endif

