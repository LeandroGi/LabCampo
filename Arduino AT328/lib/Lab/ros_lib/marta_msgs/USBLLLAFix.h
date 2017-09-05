#ifndef _ROS_marta_msgs_USBLLLAFix_h
#define _ROS_marta_msgs_USBLLLAFix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "marta_msgs/Position.h"

namespace marta_msgs
{

  class USBLLLAFix : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _remote_address_type;
      _remote_address_type remote_address;
      typedef ros::Time _measurement_time_type;
      _measurement_time_type measurement_time;
      typedef bool _usbl_measurement_flag_type;
      _usbl_measurement_flag_type usbl_measurement_flag;
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef float _accuracy_type;
      _accuracy_type accuracy;

    USBLLLAFix():
      header(),
      remote_address(0),
      measurement_time(),
      usbl_measurement_flag(0),
      position(),
      accuracy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->remote_address >> (8 * 0)) & 0xFF;
      offset += sizeof(this->remote_address);
      *(outbuffer + offset + 0) = (this->measurement_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->measurement_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->measurement_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->measurement_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement_time.sec);
      *(outbuffer + offset + 0) = (this->measurement_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->measurement_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->measurement_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->measurement_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_usbl_measurement_flag;
      u_usbl_measurement_flag.real = this->usbl_measurement_flag;
      *(outbuffer + offset + 0) = (u_usbl_measurement_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->usbl_measurement_flag);
      offset += this->position.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_accuracy;
      u_accuracy.real = this->accuracy;
      *(outbuffer + offset + 0) = (u_accuracy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accuracy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accuracy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accuracy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accuracy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->remote_address =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->remote_address);
      this->measurement_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->measurement_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->measurement_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->measurement_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->measurement_time.sec);
      this->measurement_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->measurement_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->measurement_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->measurement_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->measurement_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_usbl_measurement_flag;
      u_usbl_measurement_flag.base = 0;
      u_usbl_measurement_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->usbl_measurement_flag = u_usbl_measurement_flag.real;
      offset += sizeof(this->usbl_measurement_flag);
      offset += this->position.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_accuracy;
      u_accuracy.base = 0;
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accuracy = u_accuracy.real;
      offset += sizeof(this->accuracy);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/USBLLLAFix" ); };
    const char * getMD5(){ return PSTR( "b33c485aa9084754eac640740a840896" ); };

  };

}
#endif