#ifndef _ROS_marta_msgs_CommunicationMessage_h
#define _ROS_marta_msgs_CommunicationMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"

namespace marta_msgs
{

  class CommunicationMessage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _destination_id_type;
      _destination_id_type destination_id;
      typedef uint8_t _command_type;
      _command_type command;
      typedef const char* _payload_type;
      _payload_type payload;
      typedef int16_t _payload_length_type;
      _payload_length_type payload_length;
      typedef uint8_t _priority_type;
      _priority_type priority;
      typedef uint8_t _message_id_type_type;
      _message_id_type_type message_id_type;
      typedef uint8_t _channel_type;
      _channel_type channel;
      typedef bool _with_ack_type;
      _with_ack_type with_ack;
      typedef uint8_t _retry_count_type;
      _retry_count_type retry_count;

    CommunicationMessage():
      header(),
      destination_id(0),
      command(0),
      payload(""),
      payload_length(0),
      priority(0),
      message_id_type(0),
      channel(0),
      with_ack(0),
      retry_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->destination_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->destination_id);
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      uint32_t length_payload = strlen(this->payload);
      varToArr(outbuffer + offset, length_payload);
      offset += 4;
      memcpy(outbuffer + offset, this->payload, length_payload);
      offset += length_payload;
      union {
        int16_t real;
        uint16_t base;
      } u_payload_length;
      u_payload_length.real = this->payload_length;
      *(outbuffer + offset + 0) = (u_payload_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_payload_length.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->payload_length);
      *(outbuffer + offset + 0) = (this->priority >> (8 * 0)) & 0xFF;
      offset += sizeof(this->priority);
      *(outbuffer + offset + 0) = (this->message_id_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_id_type);
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
      offset += this->header.deserialize(inbuffer + offset);
      this->destination_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->destination_id);
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      uint32_t length_payload;
      arrToVar(length_payload, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_payload; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_payload-1]=0;
      this->payload = (char *)(inbuffer + offset-1);
      offset += length_payload;
      union {
        int16_t real;
        uint16_t base;
      } u_payload_length;
      u_payload_length.base = 0;
      u_payload_length.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_payload_length.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->payload_length = u_payload_length.real;
      offset += sizeof(this->payload_length);
      this->priority =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->priority);
      this->message_id_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_id_type);
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

    const char * getType(){ return PSTR( "marta_msgs/CommunicationMessage" ); };
    const char * getMD5(){ return PSTR( "47e6316d7f59608a47ffc3c270d09748" ); };

  };

}
#endif