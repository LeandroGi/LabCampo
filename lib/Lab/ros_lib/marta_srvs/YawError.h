#ifndef _ROS_SERVICE_YawError_h
#define _ROS_SERVICE_YawError_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_srvs
{

static const char YAWERROR[] PROGMEM = "marta_srvs/YawError";

  class YawErrorRequest : public ros::Msg
  {
    public:
      typedef float _yaw_ref_type;
      _yaw_ref_type yaw_ref;

    YawErrorRequest():
      yaw_ref(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw_ref;
      u_yaw_ref.real = this->yaw_ref;
      *(outbuffer + offset + 0) = (u_yaw_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_ref.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_ref.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_ref.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_ref);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_yaw_ref;
      u_yaw_ref.base = 0;
      u_yaw_ref.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_ref.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_ref.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_ref.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_ref = u_yaw_ref.real;
      offset += sizeof(this->yaw_ref);
     return offset;
    }

    const char * getType(){ return YAWERROR; };
    const char * getMD5(){ return PSTR( "d2a2ef9ebddd1593224e50aa806ada4c" ); };

  };

  class YawErrorResponse : public ros::Msg
  {
    public:
      typedef float _error_phi_type;
      _error_phi_type error_phi;

    YawErrorResponse():
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

    const char * getType(){ return YAWERROR; };
    const char * getMD5(){ return PSTR( "99f897fa2f6cdd0f1287a118a2823fe8" ); };

  };

  class YawError {
    public:
    typedef YawErrorRequest Request;
    typedef YawErrorResponse Response;
  };

}
#endif
