/* Run audio-state callbacks, refresh scaled gains when needed, then update the backend. */
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct SaveBlock {
    u8 pad[0xD5A];
    u8 scaleY;
    u8 scaleX;
    u8 scaleZ;
} SaveBlock;

typedef struct Obj30E8 {
    u8 pad0[0x1C];
    s32 x;
    s32 y;
    s32 z;
    u8 pad28[0x60 - 0x28];
    s32 busy;
    s32 scale;
    s32 sx;
    s32 sy;
    s32 sz;
} Obj30E8;

typedef char audio_time_pointer[sizeof(void *) == 4 ? 1 : -1];
typedef char audio_time_busy[(unsigned long)&((Obj30E8 *)0)->busy == 0x60 ? 1 : -1];
typedef char audio_time_gain[(unsigned long)&((SaveBlock *)0)->scaleX == 0xD5B ? 1 : -1];
extern SaveBlock *saveBlock;
extern void func_800A2FCC(Obj30E8 *obj);
extern void func_8001D10C(Obj30E8 *obj, s32 arg);

void func_800A30E8(Obj30E8 *obj, s32 arg) {
    func_800A2FCC(obj);
    if (obj->busy == 0) {
        SaveBlock *sb = saveBlock;
        obj->busy = 1;
        obj->scale = sb->scaleX << 11;
        obj->sx = (obj->x * sb->scaleX) >> 4;
        obj->sy = (obj->y * sb->scaleY) >> 4;
        obj->sz = (obj->z * sb->scaleZ) >> 4;
    }
    /* Empty constraints keep the busy clear at the original call boundary. */
    __asm__("" : : "r"(obj));
    obj->busy = 0;
    __asm__("" : : "m"(obj->busy));
    func_8001D10C(obj, arg);
}
