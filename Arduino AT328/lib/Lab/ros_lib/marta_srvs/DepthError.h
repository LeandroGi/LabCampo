#ifndef _ROS_SERVICE_DepthError_h
#define _ROS_SERVICE_DepthError_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_srvs
{

static const char DEPTHERROR[] PROGMEM = "marta_srvs/DepthError";

  class DepthErrorRequest : public ros::Msg
  {
    public:
      typedef float _depth_ref_type;
      _depth_ref_type depth_ref;

    DepthErrorRequest():
      depth_ref(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_depth_ref;
      u_depth_ref.real = this->depth_ref;
      *(outbuffer + offset + 0) = (u_depth_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_depth_ref.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_depth_ref.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_depth_ref.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->depth_ref);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_depth_ref;
      u_depth_ref.base = 0;
      u_depth_ref.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_depth_ref.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_depth_ref.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_depth_ref.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->depth_ref = u_depth_ref.real;
      offset += sizeof(this->depth_ref);
     return offset;
    }

    const char * getType(){ return DEPTHERROR; };
    const char * getMD5(){ return PSTR( "bc883109879e1c05b5b063a552867a40" ); };

  };

  class DepthErrorResponse : public ros::Msg
  {
    public:
      typedef float _error_prof_type;
      _error_prof_type error_prof;

    DepthErrorResponse():
      error_prof(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_error_prof;
      u_error_prof.real = this->error_prof;
      *(outbuffer + offset + 0) = (u_error_prof.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_prof.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_prof.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_prof.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_prof);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_error_prof;
      u_error_prof.base = 0;
      u_error_prof.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_prof.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_prof.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_prof.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_prof = u_error_prof.real;
      offset += sizeof(this->error_prof);
     return offset;
    }

    const char * getType(){ return DEPTHERROR; };
    const char * getMD5(){ return PSTR( "06de6e96e5eda282f03fbe9ecbae7d72" ); };

  };

  class DepthError {
    public:
    typedef DepthErrorRequest Request;
    typedef DepthErrorResponse Response;
  };

}
#endif
