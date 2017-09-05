#ifndef _ROS_SERVICE_RollError_h
#define _ROS_SERVICE_RollError_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_srvs
{

static const char ROLLERROR[] PROGMEM = "marta_srvs/RollError";

  class RollErrorRequest : public ros::Msg
  {
    public:
      typedef float _roll_ref_type;
      _roll_ref_type roll_ref;

    RollErrorRequest():
      roll_ref(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_roll_ref;
      u_roll_ref.real = this->roll_ref;
      *(outbuffer + offset + 0) = (u_roll_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_ref.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_ref.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_ref.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_ref);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_roll_ref;
      u_roll_ref.base = 0;
      u_roll_ref.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_ref.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll_ref.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll_ref.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll_ref = u_roll_ref.real;
      offset += sizeof(this->roll_ref);
     return offset;
    }

    const char * getType(){ return ROLLERROR; };
    const char * getMD5(){ return PSTR( "2f2ca9c0e07b7ecc02b3ccad3f2bccbe" ); };

  };

  class RollErrorResponse : public ros::Msg
  {
    public:
      typedef float _error_phi_type;
      _error_phi_type error_phi;

    RollErrorResponse():
      error_phi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_error_phi;
      u_error_phi.real = this->error_phi;
      *(outbuffer + offset + 0) = (u_error_phi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_phi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_phi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_phi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_phi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_error_phi;
      u_error_phi.base = 0;
      u_error_phi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_phi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_phi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_phi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_phi = u_error_phi.real;
      offset += sizeof(this->error_phi);
     return offset;
    }

    const char * getType(){ return ROLLERROR; };
    const char * getMD5(){ return PSTR( "99f897fa2f6cdd0f1287a118a2823fe8" ); };

  };

  class RollError {
    public:
    typedef RollErrorRequest Request;
    typedef RollErrorResponse Response;
  };

}
#endif
