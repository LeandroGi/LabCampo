#ifndef _ROS_marta_msgs_SideScanSonar_h
#define _ROS_marta_msgs_SideScanSonar_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "std_msgs/UInt8MultiArray.h"

namespace marta_msgs
{

  class SideScanSonar : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::UInt8MultiArray _left_beam_type;
      _left_beam_type left_beam;
      typedef std_msgs::UInt8MultiArray _right_beam_type;
      _right_beam_type right_beam;

    SideScanSonar():
      header(),
      left_beam(),
      right_beam()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->left_beam.serialize(outbuffer + offset);
      offset += this->right_beam.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->left_beam.deserialize(inbuffer + offset);
      offset += this->right_beam.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/SideScanSonar" ); };
    const char * getMD5(){ return PSTR( "5cce2c3f28a2d67b6f219db7b6517869" ); };

  };

}
#endif