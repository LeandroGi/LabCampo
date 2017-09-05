#ifndef _ROS_marta_msgs_FileTransfert_h
#define _ROS_marta_msgs_FileTransfert_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace marta_msgs
{

  class FileTransfert : public ros::Msg
  {
    public:
      typedef uint8_t _destination_id_type;
      _destination_id_type destination_id;
      typedef const char* _filename_type;
      _filename_type filename;
      typedef int16_t _filelength_length_type;
      _filelength_length_type filelength_length;
      typedef uint8_t _channel_type;
      _channel_type channel;
      typedef bool _with_ack_type;
      _with_ack_type with_ack;
      typedef uint8_t _retry_count_type;
      _retry_count_type retry_count;
      enum { FT_HIDLE = 0 };
      enum { FT_RUNNING = 1 };
      enum { FT_COMPLETED = 2 };
      enum { FT_ABORTED = 3 };
      enum { FT_BEGIN = 4 };

    FileTransfert():
      destination_id(0),
      filename(""),
      filelength_length(0),
      channel(0),
      with_ack(0),
      retry_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->destination_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->destination_id);
      uint32_t length_filename = strlen(this->filename);
      varToArr(outbuffer + offset, length_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      union {
        int16_t real;
        uint16_t base;
      } u_filelength_length;
      u_filelength_length.real = this->filelength_length;
      *(outbuffer + offset + 0) = (u_filelength_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filelength_length.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->filelength_length);
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      union {
        bool real;
        uint8_t base;
      } u_with_ack;
      u_with_ack.real = this->with_ack;
      *(outbuffer + offset + 0) = (u_with_ack.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_ack);
      *(outbuffer + offset + 0) = (this->retry_count >> (8 * 0)) & 0xFF;
      offset += sizeof(this->retry_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->destination_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->destination_id);
      uint32_t length_filename;
      arrToVar(length_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
      union {
        int16_t real;
        uint16_t base;
      } u_filelength_length;
      u_filelength_length.base = 0;
      u_filelength_length.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filelength_length.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->filelength_length = u_filelength_length.real;
      offset += sizeof(this->filelength_length);
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
      union {
        bool real;
        uint8_t base;
      } u_with_ack;
      u_with_ack.base = 0;
      u_with_ack.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_ack = u_with_ack.real;
      offset += sizeof(this->with_ack);
      this->retry_count =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->retry_count);
     return offset;
    }

    const char * getType(){ return PSTR( "marta_msgs/FileTransfert" ); };
    const char * getMD5(){ return PSTR( "753c52c9c5b53195cd82e297b68b9cd9" ); };

  };

}
#endif