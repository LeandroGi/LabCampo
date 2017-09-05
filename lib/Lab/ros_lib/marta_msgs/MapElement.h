#ifndef _ROS_marta_msgs_MapElement_h
#define _ROS_marta_msgs_MapElement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace marta_msgs
{

  class MapElement : public ros::Msg
  {
    public:
      typedef std_msgs::String _key_type;
      _key_type key;
      typedef std_msgs::Float64 _value_type;
      _value_type value;

    MapElement():
      key(),
      value()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->key.serialize(outbuffer + offset);
      offset += this->value.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->key.deserialize(inbuffer + offset);
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/MapElement" ); };
    const char * getMD5(){ return PSTR( "c6f7cb0e8e83ac285052097bffac8487" ); };

  };

}
#endif