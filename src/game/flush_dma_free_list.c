#ifndef LEAF_NAME
#define LEAF_NAME flushDmaFreeList
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

typedef struct DmaNode {
    struct DmaNode *previous;
    struct DmaNode *next;
    int count;
} DmaNode;

extern int dmaMessageCount;
extern char dmaQueue[];
extern DmaNode *dmaActiveList;
extern DmaNode *dmaFreeList;
extern int RECEIVE_NAME(void *queue, void *message, int flags);

void LEAF_NAME(void)
{
    void *message;
    DmaNode *node;
    DmaNode *next;

    while (dmaMessageCount) {
        RECEIVE_NAME(dmaQueue, &message, 0);
        dmaMessageCount--;
    }
    node = dmaActiveList;
    while (node) {
        if (--node->count == 0) {
            next = node->next;
            if (next)
                next->previous = node->previous;
            if (node->previous)
                node->previous->next = node->next;
            else
                dmaActiveList = node->next;
            node->previous = 0;
            node->next = dmaFreeList;
            dmaFreeList = node;
            node = next;
        } else {
            node = node->next;
        }
    }
}
