#ifndef LEAF_NAME
#define LEAF_NAME dispatchWorkerRequest
#endif

#ifndef QUEUE_ADDRESS_NAME
#define QUEUE_ADDRESS_NAME getWorkerQueueAddress
#endif

#ifndef SEND_NAME
#define SEND_NAME sendMessage
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

#ifndef REQUEST_QUEUE_NAME
#define REQUEST_QUEUE_NAME workerRequestQueue
#endif

#ifndef RESPONSE_QUEUE_NAME
#define RESPONSE_QUEUE_NAME workerResponseQueue
#endif

typedef unsigned int u32;

extern unsigned char REQUEST_QUEUE_NAME[];
extern unsigned char RESPONSE_QUEUE_NAME[];
extern void *QUEUE_ADDRESS_NAME(void *object);
extern int SEND_NAME(void *queue, void *message, int flags);
extern int RECEIVE_NAME(void *queue, void **message, int flags);

void LEAF_NAME(const u32 *input) {
    struct {
        u32 request[22];
        u32 response;
    } message;
    u32 *request = message.request;

    request[0] = 0;
    request[4] = 2;
    request[5] = 0;
    request[6] = 0x800022C0;
    request[7] = 0xD0;
    request[8] = input[2];
    request[9] = 0x1000;
    request[10] = input[3];
    request[11] = 0x800;
    request[12] = 0;
    request[13] = 0;
    request[14] = 0;
    request[15] = 0;
    request[16] = input[0];
    request[17] = input[1];
    request[18] = 0;
    request[19] = 0;
    request[20] = (u32)RESPONSE_QUEUE_NAME;
    request[21] = (u32)&message.response;

    SEND_NAME(QUEUE_ADDRESS_NAME(REQUEST_QUEUE_NAME), request, 1);
    RECEIVE_NAME(RESPONSE_QUEUE_NAME, 0, 1);
}
