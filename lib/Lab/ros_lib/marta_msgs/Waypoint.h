#ifndef _ROS_marta_msgs_Waypoint_h
#define _ROS_marta_msgs_Waypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "marta_msgs/Position.h"
#include "marta_msgs/Euler.h"
#include "geometry_msgs/Vector3.h"

namespace marta_msgs
{

  class Waypoint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _sequence_type;
      _sequence_type sequence;
      typedef marta_msgs::Position _position_type;
      _position_type position;
      typedef marta_msgs::Position _pre_position_type;
      _pre_position_type pre_position;
      typedef marta_msgs::Euler _orientation_type;
      _orientation_type orientation;
      typedef marta_msgs::Position _position_tolerance_type;
      _position_tolerance_type position_tolerance;
      typedef marta_msgs::Euler _orientation_tolerance_type;
      _orientation_tolerance_type orientation_tolerance;
      typedef geometry_msgs::Vector3 _reference_type;
      _reference_type reference;
      typedef geometry_msgs::Vector3 _reference_end_type;
      _reference_end_type reference_end;
      typedef const char* _mission_type;
      _mission_type mission;
      typedef uint8_t _thrust_type;
      _thrust_type thrust;
      typedef uint8_t _mode_type;
      _mode_type mode;
      enum { MODE_ALTITUDE =  1 };
      enum { MODE_DEPTH =  0 };

    Waypoint():
      header(),
      sequence(0),
      position(),
      pre_position(),
      orientation(),
      position_tolerance(),
      orientation_tolerance(),
      reference(),
      reference_end(),
      mission(""),
      thrust(0),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sequence >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sequence);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->pre_position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->position_tolerance.serialize(outbuffer + offset);
      offset += this->orientation_tolerance.serialize(outbuffer + offset);
      offset += this->reference.serialize(outbuffer + offset);
      offset += this->reference_end.serialize(outbuffer + offset);
      uint32_t length_mission = strlen(this->mission);
      varToArr(outbuffer + offset, length_mission);
      offset += 4;
      memcpy(outbuffer + offset, this->mission, length_mission);
      offset += length_mission;
      *(outbuffer + offset + 0) = (this->thrust >> (8 * 0)) & 0xFF;
      offset += sizeof(this->thrust);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->sequence =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sequence);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->pre_position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->position_tolerance.deserialize(inbuffer + offset);
      offset += this->orientation_tolerance.deserialize(inbuffer + offset);
      offset += this->reference.deserialize(inbuffer + offset);
      offset += this->reference_end.deserialize(inbuffer + offset);
      uint32_t length_mission;
      arrToVar(length_mission, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mission; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mission-1]=0;
      this->mission = (char *)(inbuffer + offset-1);
      offset += length_mission;
      this->thrust =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->thrust);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/Waypoint" ); };
    const char * getMD5(){ return PSTR( "4371a1f71ffe3adc0c543a2bd24438d2" ); };

  };

}
#endif