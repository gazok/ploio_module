#include "pch.h"
#define BUFSIZE 100000
#define MACSIZE 6

typedef int32_t (*getenv_t) (
        const char* key,
        int32_t offset,
        void* buf,

        int32_t size);

typedef int32_t (*setenv_t) (
        const char* key,
        int32_t offset,
        const void* buf,
        int32_t size);

typedef int32_t (*retval_t) (
        int32_t code,
        const char* msg);

struct EthHeader
{
    u_int8_t dst_mac[MACSIZE];
    u_int8_t src_mac[MACSIZE];
    u_int16_t type;
};

struct IpHeader
{
    // TODO
    u_int32_t srcIp;
};

struct TcpHeader
{
    // TODO
};




class Packet // parsed packets included class
{
    // TODO : pointers of packet
public:
    Packet(const void* pkt,int64_t nbpkt);
};

// entry point of shared lib
void entrypoint (
        const char* ifname,
        const void* pkt, // packet bytes
        int64_t nbpkt, // packet size
        retval_t retval)
{
    // TODO : Parsed packet ??
    // construct packet  class; extract srcIp;
    Packet packet(pkt,nbpkt);

}