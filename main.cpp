#include "pch.h"
#define BUFSIZE 100000
#define MACSIZE 6

typedef int32_t (*retval_t) (
        int32_t code,
        const char* msg);


bool is_tcp(Packet &packet)
{
  //TODO
}

bool is_ssh(Packet &packet)
{
    if(!is_tcp(packet)) return false;
    TcpHeader *tcp_header = packet.get_tcp_header();
    if(tcp_header->dst_port==22) return true;
    return false;
}

bool ssh_attempt_ten_times_per_second(Packet &packet)
{

}

void entrypoint (
        const char* ifname, // will be replaced !
        const void* pkt,
        int64_t nbpkt,
        retval_t retval)
{

    Packet packet = Packet(&pkt,nbpkt);

    char* msg;
    int32_t code;

    if(!is_ssh(packet) || !packet.is_tcp())
    {
        msg     = new char[5];
        msg     = "OK";
        code    = 20001;
    }
    else
    {
        if(ssh_attempt_ten_times_per_second(packet))
        {
            msg   = new char[5];
            msg   = "DOWN";
            code  = 30001;
        }
    }

    retval(code,msg); // What is return value int32_t ??
    return;
}

