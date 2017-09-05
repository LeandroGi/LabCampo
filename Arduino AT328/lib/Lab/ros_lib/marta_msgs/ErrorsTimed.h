#ifndef _ROS_marta_msgs_ErrorsTimed_h
#define _ROS_marta_msgs_ErrorsTimed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/String.h"
#include "marta_msgs/PoseTimed.h"

namespace marta_msgs
{

  class ErrorsTimed : public ros::Msg
  {
    public:
      typedef std_msgs::String _senderTraker_type;
      _senderTraker_type senderTraker;
      typedef marta_msgs::PoseTimed _position_type;
      _position_type position;
      typedef marta_msgs::PoseTimed _position_dt_type;
      _position_dt_type position_dt;
      typedef marta_msgs::PoseTimed _speed_type;
      _speed_type speed;
      typedef marta_msgs::PoseTimed _speed_dt_type;
      _speed_dt_type speed_dt;

    ErrorsTimed():
      senderTraker(),
      position(),
      position_dt(),
      speed(),
      speed_dt()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->senderTraker.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->position_dt.serialize(outbuffer + offset);
      offset += this->speed.serialize(outbuffer + offset);
      offset += this->speed_dt.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->senderTraker.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->position_dt.deserialize(inbuffer + offset);
      offset += this->speed.deserialize(inbuffer + offset);
      offset += this->speed_dt.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/ErrorsTimed" ); };
    const char * getMD5(){ return PSTR( "af3181237e5e0a03b0b5637a07e82fc7" ); };

  };

}
#endif