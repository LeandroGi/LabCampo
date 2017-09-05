#ifndef _ROS_marta_msgs_WallInfo_h
#define _ROS_marta_msgs_WallInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "marta_msgs/Position.h"
#include "marta_msgs/Distance.h"

namespace marta_msgs
{

  class WallInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef marta_msgs::Distance _distance_type;
      _distance_type distance;
      typedef float _angle_type;
      _angle_type angle;
      typedef bool _target_type;
      _target_type target;

    WallInfo():
      header(),
      position(),
      distance(),
      angle(0),
      target(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->distance.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        bool real;
        uint8_t base;
      } u_target;
      u_target.real = this->target;
      *(outbuffer + offset + 0) = (u_target.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->distance.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        bool real;
        uint8_t base;
      } u_target;
      u_target.base = 0;
      u_target.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->target = u_target.real;
      offset += sizeof(this->target);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/WallInfo" ); };
    const char * getMD5(){ return PSTR( "4c024d5a636d2ed62f3e9dea2d1147c1" ); };

  };

}
#endif