#ifndef _ROS_marta_msgs_NavStatus_h
#define _ROS_marta_msgs_NavStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "marta_msgs/Position.h"
#include "marta_msgs/Euler.h"
#include "geometry_msgs/Vector3.h"

namespace marta_msgs
{

  class NavStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef marta_msgs::Euler _orientation_type;
      _orientation_type orientation;
      typedef geometry_msgs::Vector3 _ned_speed_type;
      _ned_speed_type ned_speed;
      typedef geometry_msgs::Vector3 _omega_body_type;
      _omega_body_type omega_body;
      typedef uint8_t _gps_status_type;
      _gps_status_type gps_status;
      typedef bool _initialized_type;
      _initialized_type initialized;

    NavStatus():
      header(),
      position(),
      orientation(),
      ned_speed(),
      omega_body(),
      gps_status(0),
      initialized(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->ned_speed.serialize(outbuffer + offset);
      offset += this->omega_body.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->gps_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gps_status);
      union {
        bool real;
        uint8_t base;
      } u_initialized;
      u_initialized.real = this->initialized;
      *(outbuffer + offset + 0) = (u_initialized.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initialized);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->ned_speed.deserialize(inbuffer + offset);
      offset += this->omega_body.deserialize(inbuffer + offset);
      this->gps_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gps_status);
      union {
        bool real;
        uint8_t base;
      } u_initialized;
      u_initialized.base = 0;
      u_initialized.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->initialized = u_initialized.real;
      offset += sizeof(this->initialized);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/NavStatus" ); };
    const char * getMD5(){ return PSTR( "f4d627d988cd3281eb16e7d81ce8f692" ); };

  };

}
#endif