#ifndef _ROS_marta_msgs_Perceptions_h
#define _ROS_marta_msgs_Perceptions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class Perceptions : public ros::Msg
  {
    public:
      uint32_t perceptions_length;
      typedef char* _perceptions_type;
      _perceptions_type st_perceptions;
      _perceptions_type * perceptions;

    Perceptions():
      perceptions_length(0), perceptions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->perceptions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->perceptions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->perceptions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->perceptions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->perceptions_length);
      for( uint32_t i = 0; i < perceptions_length; i++){
      uint32_t length_perceptionsi = strlen(this->perceptions[i]);
      varToArr(outbuffer + offset, length_perceptionsi);
      offset += 4;
      memcpy(outbuffer + offset, this->perceptions[i], length_perceptionsi);
      offset += length_perceptionsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t perceptions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      perceptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      perceptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      perceptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->perceptions_length);
      if(perceptions_lengthT > perceptions_length)
        this->perceptions = (char**)realloc(this->perceptions, perceptions_lengthT * sizeof(char*));
      perceptions_length = perceptions_lengthT;
      for( uint32_t i = 0; i < perceptions_length; i++){
      uint32_t length_st_perceptions;
      arrToVar(length_st_perceptions, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_perceptions; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_perceptions-1]=0;
      this->st_perceptions = (char *)(inbuffer + offset-1);
      offset += length_st_perceptions;
        memcpy( &(this->perceptions[i]), &(this->st_perceptions), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Perceptions" ); };
    const char * getMD5(){ return PSTR( "d742b7ae17a9c3e0aeef1019884d93dc" ); };

  };

}
#endif