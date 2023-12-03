#include "pch.h"
#define time_t long long
#define PR0_RAW   0
#define PR0_INET  1
#define PR0_INET6 2


setres_t *setres_ptr;

bool check_tcp(pktreg_t *pkt)
{
  // TODO
}

void initialize(setres_t setres)
{
  setres_ptr = &setres;
  return;
}

bool check_ssh(pktreg_t *pkt)
{
  // TODO
}

// Data Structure


void entrypoint(uint32_t id, struct timeval tv, pktreg_t* pkt)
/* id -> Identifier of pkt??? */


{
  int code;
  char* msg;
  if(!check_tcp(pkt) || !check_ssh(pkt))
  {
    code = 20001;
    strcpy(msg,"OK");
    (*setres_ptr)(code,msg);
  }
  time_t now_time = tv.tv_sec;
  // TODO




}





