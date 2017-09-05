#ifndef _ROS_marta_msgs_FinderInfo_h
#define _ROS_marta_msgs_FinderInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"

namespace marta_msgs
{

  class FinderInfo : public ros::Msg
  {
    public:
      typedef std_msgs::String _id_type;
      _id_type id;
      typedef std_msgs::String _uid_type;
      _uid_type uid;
      typedef bool _keep_alive_type;
      _keep_alive_type keep_alive;
      typedef std_msgs::String _manual_uid_type;
      _manual_uid_type manual_uid;
      typedef std_msgs::Float64MultiArray _params_type;
      _params_type params;

    FinderInfo():
      id(),
      uid(),
      keep_alive(0),
      manual_uid(),
      params()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      offset += this->uid.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_keep_alive;
      u_keep_alive.real = this->keep_alive;
      *(outbuffer + offset + 0) = (u_keep_alive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->keep_alive);
      offset += this->manual_uid.serialize(outbuffer + offset);
      offset += this->params.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->uid.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_keep_alive;
      u_keep_alive.base = 0;
      u_keep_alive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->keep_alive = u_keep_alive.real;
      offset += sizeof(this->keep_alive);
      offset += this->manual_uid.deserialize(inbuffer + offset);
      offset += this->params.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/FinderInfo" ); };
    const char * getMD5(){ return PSTR( "3fd7399484f6e639184cf1232d1db8ce" ); };

  };

}
#endif