#ifndef _ROS_marta_msgs_Countermeasure_h
#define _ROS_marta_msgs_Countermeasure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class Countermeasure : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef const char* _cause_type;
      _cause_type cause;

    Countermeasure():
      type(""),
      cause("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      uint32_t length_cause = strlen(this->cause);
      varToArr(outbuffer + offset, length_cause);
      offset += 4;
      memcpy(outbuffer + offset, this->cause, length_cause);
      offset += length_cause;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t length_cause;
      arrToVar(length_cause, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cause; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cause-1]=0;
      this->cause = (char *)(inbuffer + offset-1);
      offset += length_cause;
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Countermeasure" ); };
    const char * getMD5(){ return PSTR( "e026b92e234dd8e1c96f003613964cf5" ); };

  };

}
#endif