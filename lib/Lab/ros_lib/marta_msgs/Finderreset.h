#ifndef _ROS_SERVICE_Finderreset_h
#define _ROS_SERVICE_Finderreset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

static const char FINDERRESET[] PROGMEM = "marta_msgs/Finderreset";

  class FinderresetRequest : public ros::Msg
  {
    public:
      typedef bool _data_type;
      _data_type data;

    FinderresetRequest():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return FINDERRESET; };
    const char * getMD5(){ return PSTR( "8b94c1b53db61fb6aed406028ad6332a" ); };

  };

  class FinderresetResponse : public ros::Msg
  {
    public:
      typedef bool _found_type;
      _found_type found;

    FinderresetResponse():
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

    const char * getType(){ return FINDERRESET; };
    const char * getMD5(){ return PSTR( "d6c4ae35878abbcf43ece19ba68d70a6" ); };

  };

  class Finderreset {
    public:
    typedef FinderresetRequest Request;
    typedef FinderresetResponse Response;
  };

}
#endif
