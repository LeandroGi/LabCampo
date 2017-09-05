#ifndef _ROS_marta_msgs_Object_h
#define _ROS_marta_msgs_Object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/Position.h"

namespace marta_msgs
{

  class Object : public ros::Msg
  {
    public:
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef uint8_t _object_code_type;
      _object_code_type object_code;
      typedef uint8_t _object_value_type;
      _object_value_type object_value;

    Object():
      position(),
      object_code(0),
      object_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->object_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_code);
      *(outbuffer + offset + 0) = (this->object_value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      this->object_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_code);
      this->object_value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_value);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Object" ); };
    const char * getMD5(){ return PSTR( "89e4a53854cb2cf3f44c9115d1d3dfa0" ); };

  };

}
#endif