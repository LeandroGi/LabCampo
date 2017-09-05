#ifndef _ROS_marta_msgs_Thrust_h
#define _ROS_marta_msgs_Thrust_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class Thrust : public ros::Msg
  {
    public:
      typedef int16_t _mot_id_type;
      _mot_id_type mot_id;
      typedef float _mot_speed_type;
      _mot_speed_type mot_speed;
      typedef float _mot_torque_type;
      _mot_torque_type mot_torque;

    Thrust():
      mot_id(0),
      mot_speed(0),
      mot_torque(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_mot_id;
      u_mot_id.real = this->mot_id;
      *(outbuffer + offset + 0) = (u_mot_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mot_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mot_id);
      union {
        float real;
        uint32_t base;
      } u_mot_speed;
      u_mot_speed.real = this->mot_speed;
      *(outbuffer + offset + 0) = (u_mot_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mot_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mot_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mot_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mot_speed);
      union {
        float real;
        uint32_t base;
      } u_mot_torque;
      u_mot_torque.real = this->mot_torque;
      *(outbuffer + offset + 0) = (u_mot_torque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mot_torque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mot_torque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mot_torque.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mot_torque);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_mot_id;
      u_mot_id.base = 0;
      u_mot_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mot_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mot_id = u_mot_id.real;
      offset += sizeof(this->mot_id);
      union {
        float real;
        uint32_t base;
      } u_mot_speed;
      u_mot_speed.base = 0;
      u_mot_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mot_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mot_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mot_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mot_speed = u_mot_speed.real;
      offset += sizeof(this->mot_speed);
      union {
        float real;
        uint32_t base;
      } u_mot_torque;
      u_mot_torque.base = 0;
      u_mot_torque.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mot_torque.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mot_torque.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mot_torque.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mot_torque = u_mot_torque.real;
      offset += sizeof(this->mot_torque);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Thrust" ); };
    const char * getMD5(){ return PSTR( "7c72ecfd89c8b69345a4b3dca7259fe7" ); };

  };

}
#endif