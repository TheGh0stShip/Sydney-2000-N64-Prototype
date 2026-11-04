#include <sched.h>

typedef struct {
    u8 pad[0x668];
    OSScClient* clientList;
} LegacySched;

void legacyScAddClient(LegacySched* sched, OSScClient* client, OSMesgQueue* msgQ) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    client->msgQ = msgQ;
    client->next = sched->clientList;
    sched->clientList = client;

    osSetIntMask(mask);
}
