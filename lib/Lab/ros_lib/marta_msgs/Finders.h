#ifndef _ROS_marta_msgs_Finders_h
#define _ROS_marta_msgs_Finders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/FinderInfo.h"

namespace marta_msgs
{

  class Finders : public ros::Msg
  {
    public:
      uint32_t active_finders_length;
      typedef marta_msgs::FinderInfo _active_finders_type;
      _active_finders_type st_active_finders;
      _active_finders_type * active_finders;

    Finders():
      active_finders_length(0), active_finders(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_finders_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->active_finders_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->active_finders_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->active_finders_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->active_finders_length);
      for( uint32_t i = 0; i < active_finders_length; i++){
      offset += this->active_finders[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t active_finders_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      active_finders_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      active_finders_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      active_finders_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->active_finders_length);
      if(active_finders_lengthT > active_finders_length)
        this->active_finders = (marta_msgs::FinderInfo*)realloc(this->active_finders, active_finders_lengthT * sizeof(marta_msgs::FinderInfo));
      active_finders_length = active_finders_lengthT;
      for( uint32_t i = 0; i < active_finders_length; i++){
      offset += this->st_active_finders.deserialize(inbuffer + offset);
        memcpy( &(this->active_finders[i]), &(this->st_active_finders), sizeof(marta_msgs::FinderInfo));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Finders" ); };
    const char * getMD5(){ return PSTR( "2d65cd17991bac34db461370a634a9d5" ); };

  };

}
#endif