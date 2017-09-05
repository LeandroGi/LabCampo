#ifndef _ROS_marta_msgs_Gps_h
#define _ROS_marta_msgs_Gps_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "marta_msgs/Position.h"
#include "geometry_msgs/Vector3.h"
#include "marta_msgs/UTCTime.h"

namespace marta_msgs
{

  class Gps : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef uint8_t _fix_type;
      _fix_type fix;
      typedef float _h_dop_type;
      _h_dop_type h_dop;
      typedef float _p_acc_type;
      _p_acc_type p_acc;
      typedef float _s_acc_type;
      _s_acc_type s_acc;
      typedef geometry_msgs::Vector3 _speed_type;
      _speed_type speed;
      typedef marta_msgs::UTCTime _utc_time_type;
      _utc_time_type utc_time;

    Gps():
      header(),
      position(),
      fix(0),
      h_dop(0),
      p_acc(0),
      s_acc(0),
      speed(),
      utc_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->fix >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fix);
      union {
        float real;
        uint32_t base;
      } u_h_dop;
      u_h_dop.real = this->h_dop;
      *(outbuffer + offset + 0) = (u_h_dop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_h_dop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_h_dop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_h_dop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->h_dop);
      union {
        float real;
        uint32_t base;
      } u_p_acc;
      u_p_acc.real = this->p_acc;
      *(outbuffer + offset + 0) = (u_p_acc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_p_acc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_p_acc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_p_acc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->p_acc);
      union {
        float real;
        uint32_t base;
      } u_s_acc;
      u_s_acc.real = this->s_acc;
      *(outbuffer + offset + 0) = (u_s_acc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_s_acc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_s_acc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_s_acc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->s_acc);
      offset += this->speed.serialize(outbuffer + offset);
      offset += this->utc_time.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      this->fix =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->fix);
      union {
        float real;
        uint32_t base;
      } u_h_dop;
      u_h_dop.base = 0;
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->h_dop = u_h_dop.real;
      offset += sizeof(this->h_dop);
      union {
        float real;
        uint32_t base;
      } u_p_acc;
      u_p_acc.base = 0;
      u_p_acc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_p_acc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_p_acc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_p_acc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->p_acc = u_p_acc.real;
      offset += sizeof(this->p_acc);
      union {
        float real;
        uint32_t base;
      } u_s_acc;
      u_s_acc.base = 0;
      u_s_acc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_s_acc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_s_acc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_s_acc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->s_acc = u_s_acc.real;
      offset += sizeof(this->s_acc);
      offset += this->speed.deserialize(inbuffer + offset);
      offset += this->utc_time.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Gps" ); };
    const char * getMD5(){ return PSTR( "bde28ced8a2b5b7e72ba6b390f1093fb" ); };

  };

}
#endif