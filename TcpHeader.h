//
// Created by 임정환 on 11/21/23.
//

#ifndef PLOIO_SSH_MODULE__TCPHEADER_H
#define PLOIO_SSH_MODULE__TCPHEADER_H

struct TcpHeader
{
  u_int16_t src_port;
  u_int16_t dst_port;
};

#endif // PLOIO_SSH_MODULE__TCPHEADER_H
