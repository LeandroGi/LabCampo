#ifndef _ROS_marta_msgs_NedCurrent_h
#define _ROS_marta_msgs_NedCurrent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class NedCurrent : public ros::Msg
  {
    public:
      typedef float _current_north_type;
      _current_north_type current_north;
      typedef float _current_east_type;
      _current_east_type current_east;

    NedCurrent():
      current_north(0),
      current_east(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_current_north;
      u_current_north.real = this->current_north;
      *(outbuffer + offset + 0) = (u_current_north.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_north.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_north.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_north.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_north);
      union {
        float real;
        uint32_t base;
      } u_current_east;
      u_current_east.real = this->current_east;
      *(outbuffer + offset + 0) = (u_current_east.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_east.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_east.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_east.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_east);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_current_north;
      u_current_north.base = 0;
      u_current_north.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_north.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_north.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_north.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_north = u_current_north.real;
      offset += sizeof(this->current_north);
      union {
        float real;
        uint32_t base;
      } u_current_east;
      u_current_east.base = 0;
      u_current_east.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_east.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_east.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_east.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_east = u_current_east.real;
      offset += sizeof(this->current_east);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/NedCurrent" ); };
    const char * getMD5(){ return PSTR( "61a30090bd6022e7d0609317eb2dc669" ); };

  };

}
#endif