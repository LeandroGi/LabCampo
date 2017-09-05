#ifndef _ROS_SERVICE_Control_h
#define _ROS_SERVICE_Control_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_core
{

static const char CONTROL[] PROGMEM = "marta_core/Control";

  class ControlRequest : public ros::Msg
  {
    public:
      uint32_t trackers_length;
      typedef char* _trackers_type;
      _trackers_type st_trackers;
      _trackers_type * trackers;

    ControlRequest():
      trackers_length(0), trackers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trackers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trackers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trackers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trackers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trackers_length);
      for( uint32_t i = 0; i < trackers_length; i++){
      uint32_t length_trackersi = strlen(this->trackers[i]);
      varToArr(outbuffer + offset, length_trackersi);
      offset += 4;
      memcpy(outbuffer + offset, this->trackers[i], length_trackersi);
      offset += length_trackersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t trackers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trackers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trackers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trackers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trackers_length);
      if(trackers_lengthT > trackers_length)
        this->trackers = (char**)realloc(this->trackers, trackers_lengthT * sizeof(char*));
      trackers_length = trackers_lengthT;
      for( uint32_t i = 0; i < trackers_length; i++){
      uint32_t length_st_trackers;
      arrToVar(length_st_trackers, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_trackers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_trackers-1]=0;
      this->st_trackers = (char *)(inbuffer + offset-1);
      offset += length_st_trackers;
        memcpy( &(this->trackers[i]), &(this->st_trackers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return CONTROL; };
    const char * getMD5(){ return PSTR( "17e205ba66c510eef18f8d90c924d3d1" ); };

  };

  class ControlResponse : public ros::Msg
  {
    public:
      typedef int8_t _status_type;
      _status_type status;

    ControlResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return CONTROL; };
    const char * getMD5(){ return PSTR( "581cc55c12abfc219e446416014f6d0e" ); };

  };

  class Control {
    public:
    typedef ControlRequest Request;
    typedef ControlResponse Response;
  };

}
#endif
