//
// Created by 임정환 on 11/21/23.
//
#ifndef PLOIO_SSH_MODULE__PACKET_H
#define PLOIO_SSH_MODULE__PACKET_H
#include "TcpHeader.h"
#include "IpHeader.h"
#include "EtherHeader.h"

class Packet // parsed packets included class
{
  // TODO : pointers of packet
  IpHeader *_ip_header;
  TcpHeader *_tcp_header;
  bool _is_tcp;
public:
  Packet(const void* pkt,int64_t nbpkt);
  TcpHeader* get_tcp_header();
  bool is_tcp();
};




#endif // PLOIO_SSH_MODULE__PACKET_H
