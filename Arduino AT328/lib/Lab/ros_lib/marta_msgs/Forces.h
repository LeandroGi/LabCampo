#ifndef _ROS_marta_msgs_Forces_h
#define _ROS_marta_msgs_Forces_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class Forces : public ros::Msg
  {
    public:
      typedef float _surge_type;
      _surge_type surge;
      typedef float _sway_type;
      _sway_type sway;
      typedef float _heave_type;
      _heave_type heave;

    Forces():
      surge(0),
      sway(0),
      heave(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_surge;
      u_surge.real = this->surge;
      *(outbuffer + offset + 0) = (u_surge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_surge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_surge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_surge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->surge);
      union {
        float real;
        uint32_t base;
      } u_sway;
      u_sway.real = this->sway;
      *(outbuffer + offset + 0) = (u_sway.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sway.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sway.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sway.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sway);
      union {
        float real;
        uint32_t base;
      } u_heave;
      u_heave.real = this->heave;
      *(outbuffer + offset + 0) = (u_heave.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heave.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heave.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heave.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heave);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_surge;
      u_surge.base = 0;
      u_surge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_surge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_surge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_surge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->surge = u_surge.real;
      offset += sizeof(this->surge);
      union {
        float real;
        uint32_t base;
      } u_sway;
      u_sway.base = 0;
      u_sway.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sway.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sway.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sway.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sway = u_sway.real;
      offset += sizeof(this->sway);
      union {
        float real;
        uint32_t base;
      } u_heave;
      u_heave.base = 0;
      u_heave.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heave.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heave.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heave.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heave = u_heave.real;
      offset += sizeof(this->heave);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Forces" ); };
    const char * getMD5(){ return PSTR( "4a16014954926a41d2c3ea558631559b" ); };

  };

}
#endif