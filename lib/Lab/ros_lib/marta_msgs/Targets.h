#ifndef _ROS_marta_msgs_Targets_h
#define _ROS_marta_msgs_Targets_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/TargetParams.h"

namespace marta_msgs
{

  class Targets : public ros::Msg
  {
    public:
      uint32_t active_target_length;
      typedef marta_msgs::TargetParams _active_target_type;
      _active_target_type st_active_target;
      _active_target_type * active_target;

    Targets():
      active_target_length(0), active_target(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_target_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->active_target_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->active_target_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->active_target_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->active_target_length);
      for( uint32_t i = 0; i < active_target_length; i++){
      offset += this->active_target[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t active_target_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      active_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      active_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      active_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->active_target_length);
      if(active_target_lengthT > active_target_length)
        this->active_target = (marta_msgs::TargetParams*)realloc(this->active_target, active_target_lengthT * sizeof(marta_msgs::TargetParams));
      active_target_length = active_target_lengthT;
      for( uint32_t i = 0; i < active_target_length; i++){
      offset += this->st_active_target.deserialize(inbuffer + offset);
        memcpy( &(this->active_target[i]), &(this->st_active_target), sizeof(marta_msgs::TargetParams));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Targets" ); };
    const char * getMD5(){ return PSTR( "bd2986319df6d637e2386be5319e0fa7" ); };

  };

}
#endif