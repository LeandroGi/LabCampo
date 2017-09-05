#ifndef _ROS_marta_msgs_P900_h
#define _ROS_marta_msgs_P900_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class P900 : public ros::Msg
  {
    public:
      float beam_all_element[768];
      float beam_all_index[768];
      float beam_filt_element[768];
      float beam_filt_index[768];

    P900():
      beam_all_element(),
      beam_all_index(),
      beam_filt_element(),
      beam_filt_index()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 768; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->beam_all_element[i]);
      }
      for( uint32_t i = 0; i < 768; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->beam_all_index[i]);
      }
      for( uint32_t i = 0; i < 768; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->beam_filt_element[i]);
      }
      for( uint32_t i = 0; i < 768; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->beam_filt_index[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 768; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beam_all_element[i]));
      }
      for( uint32_t i = 0; i < 768; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beam_all_index[i]));
      }
      for( uint32_t i = 0; i < 768; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beam_filt_element[i]));
      }
      for( uint32_t i = 0; i < 768; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beam_filt_index[i]));
      }
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/P900" ); };
    const char * getMD5(){ return PSTR( "e5ef8a90672ffb81d78c71e4b20efa6b" ); };

  };

}
#endif