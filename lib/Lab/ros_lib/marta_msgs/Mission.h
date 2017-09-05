#ifndef _ROS_marta_msgs_Mission_h
#define _ROS_marta_msgs_Mission_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"
#include "marta_msgs/Map.h"

namespace marta_msgs
{

  class Mission : public ros::Msg
  {
    public:
      typedef std_msgs::String _mission_type;
      _mission_type mission;
      typedef std_msgs::String _sub_mission_type;
      _sub_mission_type sub_mission;
      typedef std_msgs::UInt16 _seq_type;
      _seq_type seq;
      typedef marta_msgs::Map _parameters_type;
      _parameters_type parameters;

    Mission():
      mission(),
      sub_mission(),
      seq(),
      parameters()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->mission.serialize(outbuffer + offset);
      offset += this->sub_mission.serialize(outbuffer + offset);
      offset += this->seq.serialize(outbuffer + offset);
      offset += this->parameters.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->mission.deserialize(inbuffer + offset);
      offset += this->sub_mission.deserialize(inbuffer + offset);
      offset += this->seq.deserialize(inbuffer + offset);
      offset += this->parameters.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Mission" ); };
    const char * getMD5(){ return PSTR( "fb1c98949cb0bac32c8a27d0e3b5316c" ); };

  };

}
#endif