#ifndef _ROS_marta_msgs_TransferProgress_h
#define _ROS_marta_msgs_TransferProgress_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"

namespace marta_msgs
{

  class TransferProgress : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _total_size_type;
      _total_size_type total_size;
      typedef int16_t _transferred_size_type;
      _transferred_size_type transferred_size;

    TransferProgress():
      header(),
      total_size(0),
      transferred_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_total_size;
      u_total_size.real = this->total_size;
      *(outbuffer + offset + 0) = (u_total_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_size.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->total_size);
      union {
        int16_t real;
        uint16_t base;
      } u_transferred_size;
      u_transferred_size.real = this->transferred_size;
      *(outbuffer + offset + 0) = (u_transferred_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transferred_size.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transferred_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_total_size;
      u_total_size.base = 0;
      u_total_size.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_size.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->total_size = u_total_size.real;
      offset += sizeof(this->total_size);
      union {
        int16_t real;
        uint16_t base;
      } u_transferred_size;
      u_transferred_size.base = 0;
      u_transferred_size.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transferred_size.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transferred_size = u_transferred_size.real;
      offset += sizeof(this->transferred_size);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/TransferProgress" ); };
    const char * getMD5(){ return PSTR( "2840e13768479c3ffb7b384bade6bfa4" ); };

  };

}
#endif