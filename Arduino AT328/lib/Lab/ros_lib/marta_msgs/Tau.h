#ifndef _ROS_marta_msgs_Tau_h
#define _ROS_marta_msgs_Tau_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/String.h"
#include "marta_msgs/Forces.h"
#include "marta_msgs/Euler.h"

namespace marta_msgs
{

  class Tau : public ros::Msg
  {
    public:
      typedef std_msgs::String _sender_type;
      _sender_type sender;
      typedef marta_msgs::Forces _tau1_type;
      _tau1_type tau1;
      typedef marta_msgs::Euler _tau2_type;
      _tau2_type tau2;

    Tau():
      sender(),
      tau1(),
      tau2()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->sender.serialize(outbuffer + offset);
      offset += this->tau1.serialize(outbuffer + offset);
      offset += this->tau2.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->sender.deserialize(inbuffer + offset);
      offset += this->tau1.deserialize(inbuffer + offset);
      offset += this->tau2.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Tau" ); };
    const char * getMD5(){ return PSTR( "7b2fd16fe1ef855a552a86c3d0dc3277" ); };

  };

}
#endif