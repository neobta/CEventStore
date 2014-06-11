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

