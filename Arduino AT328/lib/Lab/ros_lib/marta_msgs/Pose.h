#ifndef _ROS_marta_msgs_Pose_h
#define _ROS_marta_msgs_Pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/Position.h"
#include "marta_msgs/Euler.h"

namespace marta_msgs
{

  class Pose : public ros::Msg
  {
    public:
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef marta_msgs::Euler _orientation_type;
      _orientation_type orientation;

    Pose():
      position(),
      orientation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Pose" ); };
    const char * getMD5(){ return PSTR( "8e95fab8ecc7ae839c5ebe11a9b5ecb7" ); };

  };

}
#endif