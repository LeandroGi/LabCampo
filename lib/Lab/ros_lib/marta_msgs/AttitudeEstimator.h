#ifndef _ROS_marta_msgs_AttitudeEstimator_h
#define _ROS_marta_msgs_AttitudeEstimator_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "std_msgs/Bool.h"
#include "marta_msgs/Euler.h"
#include "std_msgs/Float32.h"

namespace marta_msgs
{

  class AttitudeEstimator : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Bool _filter_initialized_type;
      _filter_initialized_type filter_initialized;
      typedef marta_msgs::Euler _orientation_type;
      _orientation_type orientation;
      typedef std_msgs::Float32 _corrected_fog_measurement_type;
      _corrected_fog_measurement_type corrected_fog_measurement;
      typedef std_msgs::Float32 _kia_type;
      _kia_type kia;
      typedef std_msgs::Float32 _kib_type;
      _kib_type kib;
      typedef std_msgs::Float32 _ang_check1_type;
      _ang_check1_type ang_check1;
      typedef std_msgs::Float32 _ang_check2_type;
      _ang_check2_type ang_check2;

    AttitudeEstimator():
      header(),
      filter_initialized(),
      orientation(),
      corrected_fog_measurement(),
      kia(),
      kib(),
      ang_check1(),
      ang_check2()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->filter_initialized.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->corrected_fog_measurement.serialize(outbuffer + offset);
      offset += this->kia.serialize(outbuffer + offset);
      offset += this->kib.serialize(outbuffer + offset);
      offset += this->ang_check1.serialize(outbuffer + offset);
      offset += this->ang_check2.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->filter_initialized.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->corrected_fog_measurement.deserialize(inbuffer + offset);
      offset += this->kia.deserialize(inbuffer + offset);
      offset += this->kib.deserialize(inbuffer + offset);
      offset += this->ang_check1.deserialize(inbuffer + offset);
      offset += this->ang_check2.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/AttitudeEstimator" ); };
    const char * getMD5(){ return PSTR( "4d1c1a8718ff71a76d1a086f4585a80d" ); };

  };

}
#endif