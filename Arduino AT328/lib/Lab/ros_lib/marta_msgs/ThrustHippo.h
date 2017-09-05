#ifndef _ROS_marta_msgs_ThrustHippo_h
#define _ROS_marta_msgs_ThrustHippo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class ThrustHippo : public ros::Msg
  {
    public:
      typedef float _p_l_type;
      _p_l_type p_l;
      typedef float _p_r_type;
      _p_r_type p_r;
      typedef float _t_l_type;
      _t_l_type t_l;
      typedef float _t_r_type;
      _t_r_type t_r;

    ThrustHippo():
      p_l(0),
      p_r(0),
      t_l(0),
      t_r(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_p_l;
      u_p_l.real = this->p_l;
      *(outbuffer + offset + 0) = (u_p_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_p_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_p_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_p_l.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->p_l);
      union {
        float real;
        uint32_t base;
      } u_p_r;
      u_p_r.real = this->p_r;
      *(outbuffer + offset + 0) = (u_p_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_p_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_p_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_p_r.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->p_r);
      union {
        float real;
        uint32_t base;
      } u_t_l;
      u_t_l.real = this->t_l;
      *(outbuffer + offset + 0) = (u_t_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_t_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_t_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_t_l.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t_l);
      union {
        float real;
        uint32_t base;
      } u_t_r;
      u_t_r.real = this->t_r;
      *(outbuffer + offset + 0) = (u_t_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_t_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_t_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_t_r.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t_r);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_p_l;
      u_p_l.base = 0;
      u_p_l.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_p_l.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_p_l.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_p_l.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->p_l = u_p_l.real;
      offset += sizeof(this->p_l);
      union {
        float real;
        uint32_t base;
      } u_p_r;
      u_p_r.base = 0;
      u_p_r.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_p_r.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_p_r.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_p_r.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->p_r = u_p_r.real;
      offset += sizeof(this->p_r);
      union {
        float real;
        uint32_t base;
      } u_t_l;
      u_t_l.base = 0;
      u_t_l.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_t_l.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_t_l.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_t_l.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->t_l = u_t_l.real;
      offset += sizeof(this->t_l);
      union {
        float real;
        uint32_t base;
      } u_t_r;
      u_t_r.base = 0;
      u_t_r.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_t_r.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_t_r.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_t_r.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->t_r = u_t_r.real;
      offset += sizeof(this->t_r);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/ThrustHippo" ); };
    const char * getMD5(){ return PSTR( "001ae518ad7644b8fb7d66bb0d59dfa0" ); };

  };

}
#endif