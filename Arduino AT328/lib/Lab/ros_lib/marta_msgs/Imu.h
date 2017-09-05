#ifndef _ROS_marta_msgs_Imu_h
#define _ROS_marta_msgs_Imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "marta_msgs/Euler.h"
#include "geometry_msgs/Vector3.h"

namespace marta_msgs
{

  class Imu : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef marta_msgs::Euler _orientation_type;
      _orientation_type orientation;
      typedef geometry_msgs::Vector3 _angular_rate_type;
      _angular_rate_type angular_rate;
      typedef geometry_msgs::Vector3 _magnetic_field_type;
      _magnetic_field_type magnetic_field;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Vector3 _free_acceleration_type;
      _free_acceleration_type free_acceleration;

    Imu():
      header(),
      orientation(),
      angular_rate(),
      magnetic_field(),
      acceleration(),
      free_acceleration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->angular_rate.serialize(outbuffer + offset);
      offset += this->magnetic_field.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->free_acceleration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->angular_rate.deserialize(inbuffer + offset);
      offset += this->magnetic_field.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->free_acceleration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Imu" ); };
    const char * getMD5(){ return PSTR( "d301cdfec66c690c9c7d83b39b850fed" ); };

  };

}
#endif