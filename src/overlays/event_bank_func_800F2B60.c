typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct { u16 a; u16 start; u8 pad[36]; } Rec;
typedef struct { u8 pad[28]; Rec *recs; } Tab;
extern void func_800B9830(u8 *obj, s32 idx, s32 z, s32 *out, u16 *len);
s32 func_8007BED0(u8 *obj)
{
    s32 out;
    u16 len;
    s32 i = *(s32 *)(obj + 264);
    func_800B9830(obj, i, 0, &out, &len);
    out = out * (len - (u16)(*(u16 *)(obj + 252) - (*(Tab **)(obj + 244))->recs[*(s32 *)(obj + 264)].start)) / len;
    return out;
}
