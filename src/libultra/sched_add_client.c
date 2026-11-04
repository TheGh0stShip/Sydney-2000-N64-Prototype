#include <sched.h>

void osScAddClient(OSSched* sched, OSScClient* client, OSMesgQueue* msgQ) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    client->msgQ = msgQ;
    client->next = sched->clientList;
    sched->clientList = client;

    osSetIntMask(mask);
}
