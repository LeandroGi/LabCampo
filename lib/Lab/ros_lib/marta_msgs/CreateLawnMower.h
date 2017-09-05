#ifndef _ROS_SERVICE_CreateLawnMower_h
#define _ROS_SERVICE_CreateLawnMower_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

static const char CREATELAWNMOWER[] PROGMEM = "marta_msgs/CreateLawnMower";

  class CreateLawnMowerRequest : public ros::Msg
  {
    public:
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef float _reference_type;
      _reference_type reference;
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef uint16_t _width_type;
      _width_type width;
      typedef uint16_t _length_type;
      _length_type length;
      typedef int16_t _bearing_type;
      _bearing_type bearing;
      typedef uint8_t _payload_type_type;
      _payload_type_type payload_type;
      typedef float _spacing_type;
      _spacing_type spacing;
      typedef float _speed_type;
      _speed_type speed;
      enum { MODE_ALTITUDE =  1 };
      enum { MODE_DEPTH =  0 };
      enum { PAYLOAD_ACOUSTIC =  97 };
      enum { PAYLOAD_OPTICAL =  111 };
      enum { PAYLOAD_BOTH =  98 };

    CreateLawnMowerRequest():
      latitude(0),
      longitude(0),
      reference(0),
      mode(0),
      width(0),
      length(0),
      bearing(0),
      payload_type(0),
      spacing(0),
      speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        float real;
        uint32_t base;
      } u_reference;
      u_reference.real = this->reference;
      *(outbuffer + offset + 0) = (u_reference.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->length >> (8 * 1)) & 0xFF;
      offset += sizeof(this->length);
      union {
        int16_t real;
        uint16_t base;
      } u_bearing;
      u_bearing.real = this->bearing;
      *(outbuffer + offset + 0) = (u_bearing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bearing.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->bearing);
      *(outbuffer + offset + 0) = (this->payload_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->payload_type);
      union {
        float real;
        uint32_t base;
      } u_spacing;
      u_spacing.real = this->spacing;
      *(outbuffer + offset + 0) = (u_spacing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_spacing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_spacing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_spacing.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spacing);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        float real;
        uint32_t base;
      } u_reference;
      u_reference.base = 0;
      u_reference.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference = u_reference.real;
      offset += sizeof(this->reference);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      this->width =  ((uint16_t) (*(inbuffer + offset)));
      this->width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->width);
      this->length =  ((uint16_t) (*(inbuffer + offset)));
      this->length |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->length);
      union {
        int16_t real;
        uint16_t base;
      } u_bearing;
      u_bearing.base = 0;
      u_bearing.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bearing.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bearing = u_bearing.real;
      offset += sizeof(this->bearing);
      this->payload_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->payload_type);
      union {
        float real;
        uint32_t base;
      } u_spacing;
      u_spacing.base = 0;
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_spacing.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->spacing = u_spacing.real;
      offset += sizeof(this->spacing);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
     return offset;
    }

    const char * getType(){ return CREATELAWNMOWER; };
    const char * getMD5(){ return PSTR( "7f62cc21ee26791e54be68582530547f" ); };

  };

  class CreateLawnMowerResponse : public ros::Msg
  {
    public:
      typedef bool _succeeded_type;
      _succeeded_type succeeded;
      typedef const char* _cause_type;
      _cause_type cause;

    CreateLawnMowerResponse():
      succeeded(0),
      cause("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_succeeded;
      u_succeeded.real = this->succeeded;
      *(outbuffer + offset + 0) = (u_succeeded.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->succeeded);
      uint32_t length_cause = strlen(this->cause);
      varToArr(outbuffer + offset, length_cause);
      offset += 4;
      memcpy(outbuffer + offset, this->cause, length_cause);
      offset += length_cause;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_succeeded;
      u_succeeded.base = 0;
      u_succeeded.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->succeeded = u_succeeded.real;
      offset += sizeof(this->succeeded);
      uint32_t length_cause;
      arrToVar(length_cause, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cause; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cause-1]=0;
      this->cause = (char *)(inbuffer + offset-1);
      offset += length_cause;
     return offset;
    }

    const char * getType(){ return CREATELAWNMOWER; };
    const char * getMD5(){ return PSTR( "9745f9349e832654feea47ee93bc3abc" ); };

  };

  class CreateLawnMower {
    public:
    typedef CreateLawnMowerRequest Request;
    typedef CreateLawnMowerResponse Response;
  };

}
#endif
