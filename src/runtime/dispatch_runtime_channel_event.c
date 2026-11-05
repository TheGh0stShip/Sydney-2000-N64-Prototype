/* Dispatch a clock-stamped kind-7 event through a parent's child list.
 * Special kind-0x3D children always receive it; flagged children receive
 * one dispatch per matching channel entry. Save the next link before calls.
 * Target: big-endian N64 MIPS o32. Rebuilt exact: func_800B34F4, 0xFC bytes. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef struct RuntimeNode RuntimeNode;
typedef struct { s32 kind; u32 time; u32 payload[4]; } RuntimeEvent;
typedef struct { short delta,pad; void (*invoke)(void *,RuntimeEvent *); } EventMethod;
typedef struct { u8 pad[0x30]; EventMethod event; } RuntimeMethods;
struct RuntimeNode {
    s32 kind;
    RuntimeNode *parent;
    RuntimeNode *first;
    RuntimeNode *next;
    u8 gap[0xA4];
    RuntimeMethods *methods;
    u8 gapB8[8];
    u32 flags;
    s32 channel;
};
typedef char channel_event_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char channel_event_integer_width[sizeof(u32) == 4 ? 1 : -1];
typedef char channel_event_storage[sizeof(RuntimeEvent) == 0x18 ? 1 : -1];
typedef char channel_event_method[sizeof(EventMethod) == 8 ? 1 : -1];
typedef char channel_event_methods_offset[(unsigned long)&((RuntimeNode *)0)->methods == 0xB4 ? 1 : -1];
typedef char channel_event_flags_offset[(unsigned long)&((RuntimeNode *)0)->flags == 0xC0 ? 1 : -1];
typedef char channel_event_channel_offset[(unsigned long)&((RuntimeNode *)0)->channel == 0xC4 ? 1 : -1];
extern u32 runtimePropertyClock;
extern s32 runtimeChannels[13];
void func_800B34F4(RuntimeNode *root) {
    RuntimeEvent event;
    RuntimeNode *node,*next;
    s32 *channels;
    u32 i;
    s32 specialKind=0x3D;
    u32 channelFlag=0x20000;
    s32 *channelBase=runtimeChannels;
    event.kind=7;
    event.time=runtimePropertyClock;
    node=root->first;
loop:
    if(node) {
        next=node->next;
        if(node->kind==specialKind) {
            node->methods->event.invoke((u8*)node+node->methods->event.delta,&event);
            node=next;
            goto loop;
        }
        if(node->flags&channelFlag) {
            i=0;
            channels=channelBase;
            for(;i<13;i++) {
                if(node->channel==*channels) {
                    node->methods->event.invoke((u8*)node+node->methods->event.delta,&event);
                }
                channels++;
            }
        }
        /* Keep the ordinary traversal tail distinct from the special-kind tail. */
        __asm__("" : : "r"(next));
        node=next;
        goto loop;
    }
}
