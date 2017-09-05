#ifndef _ROS_marta_msgs_CANOpen_h
#define _ROS_marta_msgs_CANOpen_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "std_msgs/UInt8MultiArray.h"

namespace marta_msgs
{

  class CANOpen : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _frame_type;
      _frame_type frame;
      typedef uint16_t _device_id_type;
      _device_id_type device_id;
      typedef uint16_t _index_type;
      _index_type index;
      typedef uint8_t _sub_index_type;
      _sub_index_type sub_index;
      typedef std_msgs::UInt8MultiArray _data_type;
      _data_type data;

    CANOpen():
      header(),
      frame(0),
      device_id(0),
      index(0),
      sub_index(0),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->frame >> (8 * 0)) & 0xFF;
      offset += sizeof(this->frame);
      *(outbuffer + offset + 0) = (this->device_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->device_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->device_id);
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->index);
      *(outbuffer + offset + 0) = (this->sub_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sub_index);
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->frame =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->frame);
      this->device_id =  ((uint16_t) (*(inbuffer + offset)));
      this->device_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->device_id);
      this->index =  ((uint16_t) (*(inbuffer + offset)));
      this->index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->index);
      this->sub_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sub_index);
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/CANOpen" ); };
    const char * getMD5(){ return PSTR( "6dc480147ea1eee05c9ead2a66dc73bd" ); };

  };

}
#endif