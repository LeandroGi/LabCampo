#ifndef _ROS_marta_msgs_Dvl_h
#define _ROS_marta_msgs_Dvl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "std_msgs/UInt8MultiArray.h"
#include "geometry_msgs/Vector3.h"
#include "marta_msgs/Euler.h"

namespace marta_msgs
{

  class Dvl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::UInt8MultiArray _good_or_bad_type;
      _good_or_bad_type good_or_bad;
      typedef geometry_msgs::Vector3 _velocity_instrument_type;
      _velocity_instrument_type velocity_instrument;
      typedef bool _velocity_instrument_flag_type;
      _velocity_instrument_flag_type velocity_instrument_flag;
      typedef geometry_msgs::Vector3 _velocity_earth_type;
      _velocity_earth_type velocity_earth;
      typedef bool _velocity_earth_flag_type;
      _velocity_earth_flag_type velocity_earth_flag;
      typedef marta_msgs::Euler _orientation_type;
      _orientation_type orientation;
      typedef float _salinity_type;
      _salinity_type salinity;
      typedef float _sound_speed_type;
      _sound_speed_type sound_speed;

    Dvl():
      header(),
      good_or_bad(),
      velocity_instrument(),
      velocity_instrument_flag(0),
      velocity_earth(),
      velocity_earth_flag(0),
      orientation(),
      salinity(0),
      sound_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->good_or_bad.serialize(outbuffer + offset);
      offset += this->velocity_instrument.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_velocity_instrument_flag;
      u_velocity_instrument_flag.real = this->velocity_instrument_flag;
      *(outbuffer + offset + 0) = (u_velocity_instrument_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->velocity_instrument_flag);
      offset += this->velocity_earth.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_velocity_earth_flag;
      u_velocity_earth_flag.real = this->velocity_earth_flag;
      *(outbuffer + offset + 0) = (u_velocity_earth_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->velocity_earth_flag);
      offset += this->orientation.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_salinity;
      u_salinity.real = this->salinity;
      *(outbuffer + offset + 0) = (u_salinity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_salinity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_salinity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_salinity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->salinity);
      union {
        float real;
        uint32_t base;
      } u_sound_speed;
      u_sound_speed.real = this->sound_speed;
      *(outbuffer + offset + 0) = (u_sound_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sound_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sound_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sound_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sound_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->good_or_bad.deserialize(inbuffer + offset);
      offset += this->velocity_instrument.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_velocity_instrument_flag;
      u_velocity_instrument_flag.base = 0;
      u_velocity_instrument_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->velocity_instrument_flag = u_velocity_instrument_flag.real;
      offset += sizeof(this->velocity_instrument_flag);
      offset += this->velocity_earth.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_velocity_earth_flag;
      u_velocity_earth_flag.base = 0;
      u_velocity_earth_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->velocity_earth_flag = u_velocity_earth_flag.real;
      offset += sizeof(this->velocity_earth_flag);
      offset += this->orientation.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_salinity;
      u_salinity.base = 0;
      u_salinity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_salinity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_salinity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_salinity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->salinity = u_salinity.real;
      offset += sizeof(this->salinity);
      union {
        float real;
        uint32_t base;
      } u_sound_speed;
      u_sound_speed.base = 0;
      u_sound_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sound_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sound_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sound_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sound_speed = u_sound_speed.real;
      offset += sizeof(this->sound_speed);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Dvl" ); };
    const char * getMD5(){ return PSTR( "024f60742a8889820f1173f8a0ff9392" ); };

  };

}
#endif