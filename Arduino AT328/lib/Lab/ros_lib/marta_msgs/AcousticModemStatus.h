#ifndef _ROS_marta_msgs_AcousticModemStatus_h
#define _ROS_marta_msgs_AcousticModemStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class AcousticModemStatus : public ros::Msg
  {
    public:
      typedef uint32_t _seq_type;
      _seq_type seq;
      typedef uint8_t _status_type;
      _status_type status;
      typedef uint8_t _channel_type;
      _channel_type channel;
      enum { M_STATUS_NOT_READY = 0 };
      enum { M_STATUS_READY = 1 };
      enum { M_STATUS_OK = 2 };
      enum { M_STATUS_FAILEDIM = 3 };
      enum { M_STATUS_CANCELLEDIM = 4 };
      enum { M_STATUS_DELIVEREDIM = 5 };

    AcousticModemStatus():
      seq(0),
      status(0),
      channel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->seq >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seq >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seq >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seq >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seq);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->seq =  ((uint32_t) (*(inbuffer + offset)));
      this->seq |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seq |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seq |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->seq);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/AcousticModemStatus" ); };
    const char * getMD5(){ return PSTR( "63ae14645b4d86d8935628c0a48914a7" ); };

  };

}
#endif