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


#ifndef binSer_h
#define binSer_h

#include <iostream>
#include <string>
#include <vector>

#include <utility>

namespace ser{

class binSer{
public:
  static std::vector<char>  serialize (uint16_t number);
  static uint16_t deserializeUInt16(std::vector<char> bytes);
  static std::vector<char>  serialize (int16_t number);
  static int16_t deserializeInt16(std::vector<char> bytes);



  static std::vector<char>  serialize (uint32_t  number);
  static uint32_t  deserializeUInt32(std::vector<char> bytes);
  static std::vector<char>  serialize (int32_t number);
  static int32_t deserializeInt32(std::vector<char> bytes);


  static std::vector<char>  serialize (uint64_t  number);
  static uint64_t  deserializeUInt64(std::vector<char> bytes);
  static std::vector<char>  serialize (int64_t number);
  static int64_t deserializeInt64(std::vector<char> bytes);

  static std::vector<char> serialize(bool value);
  static bool deserializeBoolean(std::vector<char> byte);
  
  static std::vector<char> serialize(const std::string &value);
  static std::string deserializeString(const std::vector<char> &byte);

  static std::vector<std::pair<int,std::vector<char>>> getIndividualValues(const std::vector<char> &message, uint64_t &lastMessagePosition);


}; // end class



  void addItemsTo(const std::vector<char> source, std::vector<char> &target);

}//end namespace
#endif

