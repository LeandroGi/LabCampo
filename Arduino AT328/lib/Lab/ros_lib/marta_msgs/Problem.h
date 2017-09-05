#ifndef _ROS_marta_msgs_Problem_h
#define _ROS_marta_msgs_Problem_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"

namespace marta_msgs
{

  class Problem : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _sender_type;
      _sender_type sender;
      typedef const char* _problemCode_type;
      _problemCode_type problemCode;

    Problem():
      header(),
      sender(""),
      problemCode("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_sender = strlen(this->sender);
      varToArr(outbuffer + offset, length_sender);
      offset += 4;
      memcpy(outbuffer + offset, this->sender, length_sender);
      offset += length_sender;
      uint32_t length_problemCode = strlen(this->problemCode);
      varToArr(outbuffer + offset, length_problemCode);
      offset += 4;
      memcpy(outbuffer + offset, this->problemCode, length_problemCode);
      offset += length_problemCode;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_sender;
      arrToVar(length_sender, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sender; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sender-1]=0;
      this->sender = (char *)(inbuffer + offset-1);
      offset += length_sender;
      uint32_t length_problemCode;
      arrToVar(length_problemCode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_problemCode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_problemCode-1]=0;
      this->problemCode = (char *)(inbuffer + offset-1);
      offset += length_problemCode;
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Problem" ); };
    const char * getMD5(){ return PSTR( "c60cd3d9d0583de24671ecbf9a8fc78d" ); };

  };

}
#endif