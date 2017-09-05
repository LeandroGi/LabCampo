#ifndef _ROS_SERVICE_Finder_h
#define _ROS_SERVICE_Finder_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/TargetParams.h"

namespace marta_msgs
{

static const char FINDER[] PROGMEM = "marta_msgs/Finder";

  class FinderRequest : public ros::Msg
  {
    public:
      typedef marta_msgs::TargetParams _data_type;
      _data_type data;

    FinderRequest():
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FINDER; };
    const char * getMD5(){ return PSTR( "a7e8ed57d48016620189b831e5216298" ); };

  };

  class FinderResponse : public ros::Msg
  {
    public:
      typedef bool _found_type;
      _found_type found;

    FinderResponse():
      found(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_found;
      u_found.real = this->found;
      *(outbuffer + offset + 0) = (u_found.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->found);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_found;
      u_found.base = 0;
      u_found.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->found = u_found.real;
      offset += sizeof(this->found);
     return offset;
    }

    const char * getType(){ return FINDER; };
    const char * getMD5(){ return PSTR( "d6c4ae35878abbcf43ece19ba68d70a6" ); };

  };

  class Finder {
    public:
    typedef FinderRequest Request;
    typedef FinderResponse Response;
  };

}
#endif
