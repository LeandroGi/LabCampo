#ifndef _ROS_marta_msgs_FinderAnswer_h
#define _ROS_marta_msgs_FinderAnswer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class FinderAnswer : public ros::Msg
  {
    public:
      typedef const char* _uid_type;
      _uid_type uid;
      typedef bool _found_type;
      _found_type found;

    FinderAnswer():
      uid(""),
      found(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_uid = strlen(this->uid);
      varToArr(outbuffer + offset, length_uid);
      offset += 4;
      memcpy(outbuffer + offset, this->uid, length_uid);
      offset += length_uid;
      union {
        bool real;
        uint8_t base;
      } u_found;
      u_found.real = this->found;
      *(outbuffer + offset + 0) = (u_found.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->found);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_uid;
      arrToVar(length_uid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uid-1]=0;
      this->uid = (char *)(inbuffer + offset-1);
      offset += length_uid;
      union {
        bool real;
        uint8_t base;
      } u_found;
      u_found.base = 0;
      u_found.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->found = u_found.real;
      offset += sizeof(this->found);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/FinderAnswer" ); };
    const char * getMD5(){ return PSTR( "d85cde869c583a91769105485a73cde4" ); };

  };

}
#endif