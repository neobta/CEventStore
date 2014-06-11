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

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "binSer.hh"
#include <stdexcept>


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

const uint32_t maxStringSize =  1048575; //1 Mega
const uint16_t maxStringSizeBytes = 3; //20bytes represetn 1 mega

template<typename T>
vector<char> getLittleEndian (T value)
{

  std::vector<char> retVal;
  long long pivot= 255; //less representative  byte on
  short adv =0; //max is 4 bytes so 4 is the maximum value
  for (short cb=0; cb < sizeof(value); ++cb)
    {
      retVal.push_back((value & pivot)>>adv);
      adv+=8;
      pivot = pivot << 8;
      
    }

  return retVal;
}



 std::vector<char>  ser::binSer::serialize (uint16_t number)
  {
    std::vector<char> retVal;   
    std::vector<char> t = getLittleEndian(number);
    for(auto ci : t)
      {
	retVal.push_back(ci);
	
      }
    return retVal;
  }


uint16_t ser::binSer::deserializeUInt16(std::vector<char> bytes){
  uint16_t retValue =0;

  for (short index =0; index < bytes.size() ; ++index )
    {
      std::bitset<8> bs(bytes[index]);
      //When extracted form the aray and converted to a number with sign
      //the byte does not have a sign is part of the original number
      //the converstion will warranty that is been using all the bytes
      //to represente the original values
      uint16_t t =  (unsigned char)bytes[index] ;
      t = t<<  (8*(index));
      retValue |= t;
      
    
    }


  return retValue;
}


 std::vector<char>  ser::binSer::serialize (int16_t number)
  {
    
    std::vector<char> retVal;
    std::vector<char> t = getLittleEndian(number);
    for(auto ci : t)
      {
	retVal.push_back(ci);
	
      }
    return retVal;
  }


int16_t ser::binSer::deserializeInt16(std::vector<char> bytes){
  int16_t retValue =0;

  for (short index =0; index < bytes.size() ; ++index )
    {
      std::bitset<8> bs(bytes[index]);
      //When extracted form the aray and converted to a number with sign
      //the byte does not have a sign is part of the original number
      //the converstion will warranty that is been using all the bytes
      //to represente the original values
      int16_t t =  (unsigned char)bytes[index] ;
      t = t<<  (8*(index));
      retValue |= t;
      
    
    }


  return retValue;
}



 std::vector<char>  ser::binSer::serialize (uint32_t  number)
  {
    
    std::vector<char> retVal;
    std::vector<char> t = getLittleEndian(number);
    for(auto ci : t)
      {
	retVal.push_back(ci);
	
      }
    return retVal;
  }


uint32_t  ser::binSer::deserializeUInt32(std::vector<char> bytes){

  uint32_t retValue =0;

  for (short index =0; index < bytes.size() ; ++index )
    {
      std::bitset<8> bs(bytes[index]);
      //When extracted form the aray and converted to a number with sign
      //the byte does not have a sign is part of the original number
      //the converstion will warranty that is been using all the bytes
      //to represente the original values
      uint32_t t =  (unsigned char)bytes[index] ;
      t = t<<  (8*(index));
      retValue |= t;
      
    
    }


  return retValue;
}






 std::vector<char>  ser::binSer::serialize (int32_t  number)
  {
    
    std::vector<char> retVal;
    std::vector<char> t = getLittleEndian(number);
    for(auto ci : t)
      {
	retVal.push_back(ci);
	
      }
    return retVal;
  }


int32_t ser::binSer::deserializeInt32(std::vector<char> bytes){
  int32_t retValue =0;

  for (short index =0; index < bytes.size() ; ++index )
    {
      std::bitset<8> bs(bytes[index]);
      //When extracted form the aray and converted to a number with sign
      //the byte does not have a sign is part of the original number
      //the converstion will warranty that is been using all the bytes
      //to represente the original values
      int32_t t =  (unsigned char)bytes[index] ;
      t = t<<  (8*(index));
      retValue |= t;
      
    
    }


  return retValue;
}



 std::vector<char>  ser::binSer::serialize (uint64_t  number)
  {
    
    std::vector<char> retVal;
    std::vector<char> t = getLittleEndian(number);
    for(auto ci : t)
      {
	retVal.push_back(ci);
	
      }
    return retVal;
  }


uint64_t  ser::binSer::deserializeUInt64(std::vector<char> bytes){

  uint64_t retValue =0;

  for (short index =0; index < bytes.size() ; ++index )
    {
      std::bitset<8> bs(bytes[index]);
      //When extracted form the aray and converted to a number with sign
      //the byte does not have a sign is part of the original number
      //the converstion will warranty that is been using all the bytes
      //to represente the original values
      uint64_t t =  (unsigned char)bytes[index] ;
      t = t<<  (8*(index));
      retValue |= t;          
    }
  return retValue;
}




 std::vector<char>  ser::binSer::serialize (int64_t  number)
  {
    
    std::vector<char> retVal;
    std::vector<char> t = getLittleEndian(number);
    for(auto ci : t)
      {
	retVal.push_back(ci);
	
      }
    return retVal;
  }


int64_t ser::binSer::deserializeInt64(std::vector<char> bytes){
  int64_t  retValue =0;

  for (short index =0; index < bytes.size() ; ++index )
    {
      std::bitset<8> bs(bytes[index]);
      //When extracted form the aray and converted to a number with sign
      //the byte does not have a sign is part of the original number
      //the converstion will warranty that is been using all the bytes
      //to represente the original values
      int64_t t =  (unsigned char)bytes[index] ;
      t = t<<  (8*(index));
      retValue |= t;
          
    }


  return retValue;
}





std::vector<char> ser::binSer::serialize(bool value){  
  std::vector<char> retVal;
  if (value)
    retVal.push_back(1);
  else
        retVal.push_back(0);

  return retVal;
}


bool ser::binSer::deserializeBoolean(std::vector<char> bytes){

  return bytes[0];
}


std::vector<char> ser::binSer::serialize(const std::string &value){
  if (value.size() > maxStringSize)
    throw std::length_error("Max String size is "+maxStringSize );

 std::vector<char> retVal;
 std::vector<char> chars(value.c_str(), value.c_str() + value.size() + 1u);

 std::vector<char> sizeser = ser::binSer::serialize(chars.size());
 // is  going to take onlye maxStringSizeBytes bytes
 
 for (int index =0; index < maxStringSizeBytes ; ++index){
   retVal.push_back(sizeser[index]);
 }



 for (char item : chars){
   retVal.push_back(item);
 }

 return retVal;

}


std::string ser::binSer::deserializeString(const std::vector<char> &bytes){
  //first byte can be avoided
  //next maxStringSizeBytes bytes contain the size of the string
  
  // std::vector<char> sizeinbytes;
  //for (int index =0; index < maxStringSizeBytes ; ++index){
  //   sizeinbytes.push_back(bytes[index]); //
  // }  

  std::string a (bytes.begin()+maxStringSizeBytes, bytes.end()-1); // l first ast value is C string null terminator

  return a;
}





void ser::addItemsTo(const vector<char> source, vector<char> &target)
{
  for (auto i : source)
    {
      target.push_back(i);
    }
}



std::vector<std::pair<int,std::vector<char>>> ser::binSer::getIndividualValues(const std::vector<char> &message, uint64_t &lastMessagePosition)
{
  std::vector<std::pair<int,std::vector<char>>> retVal;
  uint64_t index = lastMessagePosition;
  while (true)
    {

      unsigned char currentType = message[index];

      if (currentType == 0)
	{	  //Reach end of the message return

	  lastMessagePosition = index+1;

	  break;
	}

      switch (currentType)
	{
	case 1:
	  {
	  //2 bytes Int16
	    ++index;
	    uint16_t size = 2;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({1,bytes});
	    index += size;
	    break;
	  }
	case 2:
	  {
	    //4 bytes Int32
	    ++index;
	    uint16_t size = 4;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({2,bytes});
	    index += size;
	    break;
	  }
	case 3:
	  {
	    //8 bytes Int64
	    ++index;
	    uint16_t size= 8;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({3,bytes});
	    index += size;
	    break;
	  }
	case 4:
	  {
	    //2 bytes UInt16
	    ++index;
	    uint16_t size = 2;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({4,bytes});
	    index += size;
	    break;
	  }
	case 5:
	  {
	    //4 bytes UInt64
	    ++index;
	    uint16_t size= 4;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({5,bytes});
	    index += size;
	    break;
	  }
	case 6:
	  {
	    //8 bytes UInt64
	    ++index;
	    uint16_t size= 8;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({6,bytes});
	    index += size;
	    break;
	  }
	case 7:
	  {
	    //Boolean in 1 byte
	    ++index;
	    uint16_t size= 1;
	    std::vector<char> bytes(message.begin()+index,message.begin()+index+size );
	    retVal.push_back({7,bytes});
	    index += size;
	    break;
	  }
	case 10:
	  {
	  //string first
	  // Index point to type 10 next maxStringSizeBytes(3) bytes defines de size of the string
	  ++index;
	  vector<char> sizechar(message.begin()+index,message.begin()+index+ maxStringSizeBytes);
	  index += maxStringSizeBytes;
	  uint16_t size = ser::binSer::deserializeUInt16(sizechar);

	  vector<char> str (message.begin()+index, message.begin()+index+size);
	  index+= size;
	  
	  ser::addItemsTo(str,sizechar);

	  retVal.push_back({10,sizechar});

	  break;

	  }
	default:
	  throw std::domain_error(("Message contains Type that is unknow at "+std::to_string(currentType)));
	  
	}  
      
    }
  
   
  return retVal;
}
