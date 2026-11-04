#ifndef LEAF_NAME
#define LEAF_NAME broadcastMessageToClients
#endif
#ifndef SEND_MESSAGE_NAME
#define SEND_MESSAGE_NAME sendMessage
#endif

typedef struct Client Client;

struct Client {
    Client *next;
    void *queue;
};

extern void SEND_MESSAGE_NAME(void *queue, void *message, int flags);

void LEAF_NAME(void *owner, void *message) {
    Client *client = *(Client **)((char *)owner + 0x668);

    if (client != 0) {
        do {
            SEND_MESSAGE_NAME(client->queue, message, 0);
            client = client->next;
        } while (client != 0);
    }
}
