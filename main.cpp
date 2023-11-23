#include "pch.h"
#define BUFSIZE 100000
#define MACSIZE 6
#define ms long long

typedef int32_t (*retval_t) (
        int32_t code,
        const char* msg);

std::unordered_map<u_int32_t ,std::queue<ms>> ssh_attempt_map;

void entrypoint (
        const u_int32_t iftype,
        const void* pkt, // packet bytes
        int64_t nbpkt, // packet size
        retval_t retval)
{
    u_int32_t code;
    char* msg;
    size_t offset     = 0;
    u_int8_t* packet  = (u_int8_t*)pkt;
    EthHdr * pkteth   = (EthHdr *)(packet + offset);
    offset            += sizeof(*pkteth);


    if (pkteth->type != 0x08 ) /*Not a IPv4*/
    {
      strcpy(msg,"OK");
      code  = 20001;
      retval(code,msg);
      return;
    }

    IpV4Hdr *pip  = (IpV4Hdr *)(packet + offset);
    offset        += sizeof(*pip);

    if (pip->protocol != 0x06 ) /*Not a TCP*/
    {
      strcpy(msg,"OK");
      code = 20001;
      retval(code,msg);
      return;
    }

    TcpHdr * ptcp = (TcpHdr *)(packet + offset);
    if(ptcp->dst_port != 0x22)
    {
      strcpy(msg,"OK");
      code = 20001;
      retval(code,msg);
      return;
    }

    // get current time
    auto now = std::chrono::system_clock::now();

    // time to millis
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    ssh_attempt_map[iftype].push(millis.count());

    if(ssh_attempt_map.size()<10)
    {
      strcpy(msg,"OK");
      code = 20001;
      retval(code,msg);
      return;
    }

    if(millis.count() - ssh_attempt_map[iftype].front() <= 1000 ) /* 10 times attempt in a second */
    {
      strcpy(msg,"WARN");
      code = 30001;
    }
    else
    {
      strcpy(msg,"WARN");
      code = 30001;
    }
    ssh_attempt_map[iftype].pop(); /* keep 10 elements in a data structure */
    retval(code,msg);
    return;
}