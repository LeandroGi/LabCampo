#ifndef _ROS_marta_msgs_DRError_h
#define _ROS_marta_msgs_DRError_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "marta_msgs/Position.h"

namespace marta_msgs
{

  class DRError : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef marta_msgs::Position _initial_position_type;
      _initial_position_type initial_position;
      typedef marta_msgs::Position _gps_position_type;
      _gps_position_type gps_position;
      typedef marta_msgs::Position _estimated_position_type;
      _estimated_position_type estimated_position;
      typedef float _distance_error_type;
      _distance_error_type distance_error;
      typedef float _estimated_heading_type;
      _estimated_heading_type estimated_heading;
      typedef float _gps_based_heading_type;
      _gps_based_heading_type gps_based_heading;
      typedef float _estimated_distance_type;
      _estimated_distance_type estimated_distance;
      typedef float _gps_based_distance_type;
      _gps_based_distance_type gps_based_distance;
      typedef float _time_elapsed_type;
      _time_elapsed_type time_elapsed;

    DRError():
      header(),
      initial_position(),
      gps_position(),
      estimated_position(),
      distance_error(0),
      estimated_heading(0),
      gps_based_heading(0),
      estimated_distance(0),
      gps_based_distance(0),
      time_elapsed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->initial_position.serialize(outbuffer + offset);
      offset += this->gps_position.serialize(outbuffer + offset);
      offset += this->estimated_position.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->estimated_heading);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_based_heading);
      offset += serializeAvrFloat64(outbuffer + offset, this->estimated_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_based_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_elapsed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->initial_position.deserialize(inbuffer + offset);
      offset += this->gps_position.deserialize(inbuffer + offset);
      offset += this->estimated_position.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->estimated_heading));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_based_heading));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->estimated_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_based_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_elapsed));
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/DRError" ); };
    const char * getMD5(){ return PSTR( "de929d86d87ffefde4aa283ed2071c30" ); };

  };

}
#endif