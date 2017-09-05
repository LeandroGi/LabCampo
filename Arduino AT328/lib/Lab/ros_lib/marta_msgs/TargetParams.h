#ifndef _ROS_marta_msgs_TargetParams_h
#define _ROS_marta_msgs_TargetParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"

namespace marta_msgs
{

  class TargetParams : public ros::Msg
  {
    public:
      typedef std_msgs::String _uid_type;
      _uid_type uid;
      typedef std_msgs::String _id_type;
      _id_type id;
      typedef std_msgs::Float64MultiArray _params_type;
      _params_type params;

    TargetParams():
      uid(),
      id(),
      params()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->uid.serialize(outbuffer + offset);
      offset += this->id.serialize(outbuffer + offset);
      offset += this->params.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->uid.deserialize(inbuffer + offset);
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->params.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/TargetParams" ); };
    const char * getMD5(){ return PSTR( "2747e73905b58518aed1793b713cb2e8" ); };

  };

}
#endif