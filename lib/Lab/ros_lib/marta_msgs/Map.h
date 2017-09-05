#ifndef _ROS_marta_msgs_Map_h
#define _ROS_marta_msgs_Map_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/MapElement.h"

namespace marta_msgs
{

  class Map : public ros::Msg
  {
    public:
      uint32_t elements_length;
      typedef marta_msgs::MapElement _elements_type;
      _elements_type st_elements;
      _elements_type * elements;

    Map():
      elements_length(0), elements(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->elements_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->elements_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->elements_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->elements_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->elements_length);
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->elements[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t elements_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->elements_length);
      if(elements_lengthT > elements_length)
        this->elements = (marta_msgs::MapElement*)realloc(this->elements, elements_lengthT * sizeof(marta_msgs::MapElement));
      elements_length = elements_lengthT;
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->st_elements.deserialize(inbuffer + offset);
        memcpy( &(this->elements[i]), &(this->st_elements), sizeof(marta_msgs::MapElement));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Map" ); };
    const char * getMD5(){ return PSTR( "26c3a547d8140d02e2cf10bd39cbc6c3" ); };

  };

}
#endif