#ifndef _ROS_marta_msgs_ReferenceGenerators_h
#define _ROS_marta_msgs_ReferenceGenerators_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class ReferenceGenerators : public ros::Msg
  {
    public:
      uint32_t reference_generators_length;
      typedef char* _reference_generators_type;
      _reference_generators_type st_reference_generators;
      _reference_generators_type * reference_generators;

    ReferenceGenerators():
      reference_generators_length(0), reference_generators(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->reference_generators_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_generators_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->reference_generators_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->reference_generators_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_generators_length);
      for( uint32_t i = 0; i < reference_generators_length; i++){
      uint32_t length_reference_generatorsi = strlen(this->reference_generators[i]);
      varToArr(outbuffer + offset, length_reference_generatorsi);
      offset += 4;
      memcpy(outbuffer + offset, this->reference_generators[i], length_reference_generatorsi);
      offset += length_reference_generatorsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t reference_generators_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      reference_generators_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      reference_generators_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      reference_generators_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->reference_generators_length);
      if(reference_generators_lengthT > reference_generators_length)
        this->reference_generators = (char**)realloc(this->reference_generators, reference_generators_lengthT * sizeof(char*));
      reference_generators_length = reference_generators_lengthT;
      for( uint32_t i = 0; i < reference_generators_length; i++){
      uint32_t length_st_reference_generators;
      arrToVar(length_st_reference_generators, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_reference_generators; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_reference_generators-1]=0;
      this->st_reference_generators = (char *)(inbuffer + offset-1);
      offset += length_st_reference_generators;
        memcpy( &(this->reference_generators[i]), &(this->st_reference_generators), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/ReferenceGenerators" ); };
    const char * getMD5(){ return PSTR( "3027980d758285ffcf96ac217c4d353a" ); };

  };

}
#endif