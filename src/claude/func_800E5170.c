/* Runtime-stage C reconstruction: publish two zero-initialised descriptor records. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct RuntimeBufferDesc {
    u8 *data;
    u32 unk4;
    s32 kind;
    u32 unkC;
} RuntimeBufferDesc;
typedef char check_buffer_desc[sizeof(RuntimeBufferDesc) == 0x10 ? 1 : -1];

typedef struct RuntimeStreamDesc {
    u8 *data;
    s32 kind;
    u32 unk8;
    s32 mask;
    u16 width;
    u16 count;
    void *table;
} RuntimeStreamDesc;
typedef char check_stream_desc[sizeof(RuntimeStreamDesc) == 0x18 ? 1 : -1];

extern u8 *runtimeDescriptorBase;
extern u8 runtimeDescriptorTable[];
extern RuntimeBufferDesc D_801034C0;
extern RuntimeStreamDesc D_801034A0;
extern void func_80037F30(void *dst, s32 value, u32 size);

void func_800E5170(void) {
    RuntimeBufferDesc buffer;
    RuntimeStreamDesc stream;

    func_80037F30(&buffer, 0, sizeof(buffer));
    buffer.data = runtimeDescriptorBase + 0xDD0;
    buffer.kind = 3;
    D_801034C0 = buffer;
    func_80037F30(&stream, 0, sizeof(stream));
    stream.data = runtimeDescriptorBase + 0xDD8;
    stream.kind = 2;
    stream.mask = 0x1F;
    stream.width = 2;
    stream.count = 1;
    stream.table = runtimeDescriptorTable;
    D_801034A0 = stream;
}
