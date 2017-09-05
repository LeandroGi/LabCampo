#ifndef _ROS_marta_msgs_USBLFix_h
#define _ROS_marta_msgs_USBLFix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "marta_msgs/Euler.h"

namespace marta_msgs
{

  class USBLFix : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _remote_address_type;
      _remote_address_type remote_address;
      typedef geometry_msgs::Vector3 _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _motion_compensated_position_type;
      _motion_compensated_position_type motion_compensated_position;
      typedef marta_msgs::Euler _vessel_orientation_type;
      _vessel_orientation_type vessel_orientation;
      typedef float _propagation_time_type;
      _propagation_time_type propagation_time;
      typedef float _rssi_type;
      _rssi_type rssi;
      typedef float _integrity_type;
      _integrity_type integrity;
      typedef float _accuracy_type;
      _accuracy_type accuracy;

    USBLFix():
      header(),
      remote_address(0),
      position(),
      motion_compensated_position(),
      vessel_orientation(),
      propagation_time(0),
      rssi(0),
      integrity(0),
      accuracy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->remote_address >> (8 * 0)) & 0xFF;
      offset += sizeof(this->remote_address);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->motion_compensated_position.serialize(outbuffer + offset);
      offset += this->vessel_orientation.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_propagation_time;
      u_propagation_time.real = this->propagation_time;
      *(outbuffer + offset + 0) = (u_propagation_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_propagation_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_propagation_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_propagation_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->propagation_time);
      union {
        float real;
        uint32_t base;
      } u_rssi;
      u_rssi.real = this->rssi;
      *(outbuffer + offset + 0) = (u_rssi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rssi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rssi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rssi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rssi);
      union {
        float real;
        uint32_t base;
      } u_integrity;
      u_integrity.real = this->integrity;
      *(outbuffer + offset + 0) = (u_integrity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_integrity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_integrity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_integrity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->integrity);
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
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->motion_compensated_position.deserialize(inbuffer + offset);
      offset += this->vessel_orientation.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_propagation_time;
      u_propagation_time.base = 0;
      u_propagation_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_propagation_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_propagation_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_propagation_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->propagation_time = u_propagation_time.real;
      offset += sizeof(this->propagation_time);
      union {
        float real;
        uint32_t base;
      } u_rssi;
      u_rssi.base = 0;
      u_rssi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rssi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rssi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rssi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rssi = u_rssi.real;
      offset += sizeof(this->rssi);
      union {
        float real;
        uint32_t base;
      } u_integrity;
      u_integrity.base = 0;
      u_integrity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_integrity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_integrity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_integrity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->integrity = u_integrity.real;
      offset += sizeof(this->integrity);
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

    const char * getType(){ return PSTR( "marta_msgs/USBLFix" ); };
    const char * getMD5(){ return PSTR( "68c9dad22c9e7bc75ef43a95e8b585cc" ); };

  };

}
#endif