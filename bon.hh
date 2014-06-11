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

