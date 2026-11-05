/* Set the parent's activation flag, then update its child outputs.
 * Special kind-0x3D children receive activate/deactivate calls. Matching
 * channel children receive deactivate calls only when disabling output.
 * Load each next link after dispatch, preserving callback-driven list edits.
 * Big-endian N64 MIPS o32; rebuilt exact: func_800B2158, 0x12C bytes. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct RuntimeNode RuntimeNode;
typedef struct { short delta,pad; void (*invoke)(void *); } NodeMethod;
typedef struct { u8 pad[0x40]; NodeMethod activate,deactivate; } NodeMethods;
struct RuntimeNode {
    s32 kind;
    RuntimeNode *parent,*first,*next;
    u8 gap[0xA4];
    NodeMethods *methods;
    u8 gapB8[8];
    u32 flags;
    s32 channel;
    u8 gapC8[0xC];
    u16 state;
};
typedef char activation_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char activation_integer_width[sizeof(s32) == 4 ? 1 : -1];
typedef char activation_method_size[sizeof(NodeMethod) == 8 ? 1 : -1];
typedef char activation_methods_offset[(unsigned long)&((RuntimeNode *)0)->methods == 0xB4 ? 1 : -1];
typedef char activation_channel_offset[(unsigned long)&((RuntimeNode *)0)->channel == 0xC4 ? 1 : -1];
typedef char activation_state_offset[(unsigned long)&((RuntimeNode *)0)->state == 0xD4 ? 1 : -1];
extern s32 runtimeChannels[13];
void func_800B2158(RuntimeNode *root,s32 active) {
    register RuntimeNode *node __asm__("s0");
    u8 i;
    s32 specialKind;
    u32 channelFlag;
    s32 *channels;
    if(active) root->state|=4;
    else root->state&=~4;
    node=root->first;
    specialKind=0x3D;
    channelFlag=0x20000;
    channels=runtimeChannels;
loop:
    if(node) {
        if(node->kind!=specialKind) {
            if(node->flags&channelFlag) {
                for(i=0;i<13;i++) {
                    if(node->channel==channels[i]) {
                        if(!active) node->methods->deactivate.invoke((u8*)node+node->methods->deactivate.delta);
                    }
                }
            }
        } else {
            if(active) node->methods->activate.invoke((u8*)node+node->methods->activate.delta);
            else node->methods->deactivate.invoke((u8*)node+node->methods->deactivate.delta);
        }
        node=node->next;
        goto loop;
    }
}
