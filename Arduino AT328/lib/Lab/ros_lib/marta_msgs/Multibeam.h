#ifndef _ROS_marta_msgs_Multibeam_h
#define _ROS_marta_msgs_Multibeam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/Pose.h"

namespace marta_msgs
{

  class Multibeam : public ros::Msg
  {
    public:
      typedef marta_msgs::Pose _pose_type;
      _pose_type pose;
      uint32_t range_length;
      typedef float _range_type;
      _range_type st_range;
      _range_type * range;

    Multibeam():
      pose(),
      range_length(0), range(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->range_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->range_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->range_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->range_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_length);
      for( uint32_t i = 0; i < range_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->range[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t range_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      range_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      range_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      range_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->range_length);
      if(range_lengthT > range_length)
        this->range = (float*)realloc(this->range, range_lengthT * sizeof(float));
      range_length = range_lengthT;
      for( uint32_t i = 0; i < range_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_range));
        memcpy( &(this->range[i]), &(this->st_range), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Multibeam" ); };
    const char * getMD5(){ return PSTR( "735c63619162efc97e54da37b52591a9" ); };

  };

}
#endif