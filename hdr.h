//
// Created by 임정환 on 11/23/23.
//

#ifndef PLOIO_SSH_MODULE__HDR_H
#define PLOIO_SSH_MODULE__HDR_H
#include "stdint.h"
typedef struct __pktreg pktreg_t;
typedef void (*setres_t)(uint16_t code, const char* msg);

struct __pktreg {
  uint64_t  magic;
  size_t    size;
  uint8_t*  payload;
  pktreg_t* next;
}__attribute__((aligned(4)));

class IP
{

};

struct EthHdr
{
  u_int8_t dst_mac[6];
  u_int8_t src_mac[6];
  u_int16_t type;
} __attribute__((packed));


struct IpV4Hdr
{
  uint8_t     ver     : 4;
  uint8_t     ihl     : 4;
  uint8_t     dscp    : 6;
  uint8_t     ecn     : 2;
  uint16_t    len;

  uint16_t    id;
  uint16_t    flags   : 3;
  uint16_t    fragofs : 13;

  uint8_t     ttl;
  uint8_t     protocol;
  uint16_t    checksum;

  u_int32_t     srcip;
  u_int32_t     dstip;
}__attribute__((packed));

struct TcpHdr
{
  uint16_t    src_port;
  uint16_t    dst_port;

  uint32_t    seq_num;
  uint32_t    ack_num;

  uint8_t     datofs  : 4;
  uint8_t     rsrvd   : 4;
  uint8_t     flags;
  uint16_t    wndsiz;

  uint16_t    check_sum;
  uint16_t    urgptr;
}__attribute__((packed));


#endif // PLOIO_SSH_MODULE__HDR_H
