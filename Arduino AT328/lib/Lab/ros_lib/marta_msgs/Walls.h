#ifndef _ROS_marta_msgs_Walls_h
#define _ROS_marta_msgs_Walls_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "marta_msgs/WallInfo.h"

namespace marta_msgs
{

  class Walls : public ros::Msg
  {
    public:
      uint32_t found_walls_length;
      typedef marta_msgs::WallInfo _found_walls_type;
      _found_walls_type st_found_walls;
      _found_walls_type * found_walls;

    Walls():
      found_walls_length(0), found_walls(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->found_walls_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->found_walls_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->found_walls_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->found_walls_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->found_walls_length);
      for( uint32_t i = 0; i < found_walls_length; i++){
      offset += this->found_walls[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t found_walls_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      found_walls_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      found_walls_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      found_walls_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->found_walls_length);
      if(found_walls_lengthT > found_walls_length)
        this->found_walls = (marta_msgs::WallInfo*)realloc(this->found_walls, found_walls_lengthT * sizeof(marta_msgs::WallInfo));
      found_walls_length = found_walls_lengthT;
      for( uint32_t i = 0; i < found_walls_length; i++){
      offset += this->st_found_walls.deserialize(inbuffer + offset);
        memcpy( &(this->found_walls[i]), &(this->st_found_walls), sizeof(marta_msgs::WallInfo));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Walls" ); };
    const char * getMD5(){ return PSTR( "4ae08b38ed8e04a3335aef14f4e61fe7" ); };

  };

}
#endif