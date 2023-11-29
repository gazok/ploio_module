# PLOIO MODULE
## K8S Agent API 
```
/*
 * =================================== NOTICE ===================================
 * - all types follow ILP32 and LP64
 * - struct must be packed with 4B
 * - magic number after INET packet is same as an ip-protocol-number for payload
 * ==============================================================================
 */

#define PR0_RAW   0
#define PR0_INET  1
#define PR0_INET6 2

typedef struct __pktreg pktreg_t;

__attribute__((aligned(4)))
struct __pktreg {
  uint64_t  magic;
  size_t    size;
  uint8_t*  payload;
  pktreg_t* next;
};

typedef void (*setres_t)(uint16_t code, const char* msg);

void initialize(setres_t setres);
void entrypoint(uint32_t id, struct timeval tv, pktreg_t* pkt);
```

## This module detect SSH Attempts in a second ; 
* Other modules ( e.g. Detect Log4J Attack , Detect Heart Bleed Attack ) can be ;
* Follow this API 

