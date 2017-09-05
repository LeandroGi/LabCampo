#ifndef _ROS_marta_msgs_PoseTimed_h
#define _ROS_marta_msgs_PoseTimed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "ros/time.h"

namespace marta_msgs
{

  class PoseTimed : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef ros::Time _tx_type;
      _tx_type tx;
      typedef float _y_type;
      _y_type y;
      typedef ros::Time _ty_type;
      _ty_type ty;
      typedef float _z_type;
      _z_type z;
      typedef ros::Time _tz_type;
      _tz_type tz;
      typedef float _roll_type;
      _roll_type roll;
      typedef ros::Time _troll_type;
      _troll_type troll;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef ros::Time _tpitch_type;
      _tpitch_type tpitch;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef ros::Time _tyaw_type;
      _tyaw_type tyaw;

    PoseTimed():
      x(0),
      tx(),
      y(0),
      ty(),
      z(0),
      tz(),
      roll(0),
      troll(),
      pitch(0),
      tpitch(),
      yaw(0),
      tyaw()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      *(outbuffer + offset + 0) = (this->tx.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tx.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tx.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tx.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tx.sec);
      *(outbuffer + offset + 0) = (this->tx.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tx.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tx.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tx.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tx.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      *(outbuffer + offset + 0) = (this->ty.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ty.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ty.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ty.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ty.sec);
      *(outbuffer + offset + 0) = (this->ty.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ty.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ty.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ty.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ty.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      *(outbuffer + offset + 0) = (this->tz.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tz.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tz.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tz.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tz.sec);
      *(outbuffer + offset + 0) = (this->tz.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tz.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tz.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tz.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tz.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->roll);
      *(outbuffer + offset + 0) = (this->troll.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->troll.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->troll.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->troll.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->troll.sec);
      *(outbuffer + offset + 0) = (this->troll.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->troll.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->troll.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->troll.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->troll.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->pitch);
      *(outbuffer + offset + 0) = (this->tpitch.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tpitch.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tpitch.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tpitch.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tpitch.sec);
      *(outbuffer + offset + 0) = (this->tpitch.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tpitch.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tpitch.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tpitch.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tpitch.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw);
      *(outbuffer + offset + 0) = (this->tyaw.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tyaw.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tyaw.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tyaw.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tyaw.sec);
      *(outbuffer + offset + 0) = (this->tyaw.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tyaw.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tyaw.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tyaw.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tyaw.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      this->tx.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->tx.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tx.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tx.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tx.sec);
      this->tx.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->tx.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tx.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tx.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tx.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      this->ty.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->ty.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ty.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ty.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ty.sec);
      this->ty.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->ty.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ty.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ty.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ty.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      this->tz.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->tz.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tz.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tz.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tz.sec);
      this->tz.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->tz.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tz.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tz.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tz.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->roll));
      this->troll.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->troll.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->troll.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->troll.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->troll.sec);
      this->troll.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->troll.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->troll.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->troll.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->troll.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pitch));
      this->tpitch.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->tpitch.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tpitch.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tpitch.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tpitch.sec);
      this->tpitch.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->tpitch.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tpitch.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tpitch.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tpitch.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw));
      this->tyaw.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->tyaw.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tyaw.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tyaw.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tyaw.sec);
      this->tyaw.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->tyaw.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tyaw.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tyaw.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tyaw.nsec);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/PoseTimed" ); };
    const char * getMD5(){ return PSTR( "35a1175256cb4ec33816a0144c0119d7" ); };

  };

}
#endif