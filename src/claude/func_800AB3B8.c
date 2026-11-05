/* Runtime-stage C reconstruction: allocate and clear the three event-queue buffers. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;

typedef struct EventQueue {
    void *entries;
    void *slots;
    void *order;
    u16 unk0C;
    u16 count;
} EventQueue;
typedef char check_event_queue[sizeof(EventQueue) == 0x10 ? 1 : -1];

extern void *runtimeEventHeap;
extern char runtimeEventQueueTag1[];
extern char runtimeEventQueueTag2[];
extern char runtimeEventQueueTag3[];
extern s32 func_800AA804(void *heap, void **output, s32 size, const char *tag);
extern void func_800B3AFC(void *, u32, u32);
extern void func_800AB534(EventQueue *queue);

void func_800AB3B8(EventQueue *queue, u16 count) {
    func_800AA804(runtimeEventHeap, &queue->entries, count * 24, runtimeEventQueueTag1);
    func_800AA804(runtimeEventHeap, &queue->order, count * 4, runtimeEventQueueTag2);
    func_800AA804(runtimeEventHeap, &queue->slots, (count + 1) * 4, runtimeEventQueueTag3);
    func_800B3AFC(queue->entries, 0, count * 24);
    func_800B3AFC(queue->slots, 0, (count + 1) * 4);
    queue->count = count;
    func_800AB534(queue);
}
