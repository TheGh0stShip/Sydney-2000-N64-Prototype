#ifndef LEAF_NAME
#define LEAF_NAME initializeVideoMode
#endif

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 D_8005A824;
extern u16 D_8005A826;
extern u32 D_8005A828;
extern u16 D_8005A82A;
extern u32 D_8005A82C;
extern u32 D_8005A83C;
extern u32 D_8005A840[20];
extern u32 D_8005A890;
extern u32 D_8005A894[20];
extern u32 D_800661C8;
extern u32 D_800661CC;
extern u32 D_80067480[20];
extern u32 D_80068330[20];
extern u16 D_800F2740;
extern u16 D_800F2742;

extern void func_80010AA0(void);
extern void func_80010CE8(void);
extern void func_8002F260(void *destination, const void *source, u32 size);
extern void func_80034C30(void *mode);
extern void func_800351A0(u32 value);

void LEAF_NAME(u32 value)
{
    u32 *source;
    u32 *destination;
    u32 *end;

    D_8005A828 = 240;
    D_800661CC = value;
    D_8005A824 = 640;
    func_80010AA0();
    func_80034C30(D_80067480);

    source = D_80067480;
    destination = D_8005A894;
    end = source + 20;
    do {
        destination[0] = source[0];
        destination[1] = source[1];
        destination[2] = source[2];
        destination[3] = source[3];
        source += 4;
        destination += 4;
    } while (source != end);

    D_8005A890 = (u32)D_80067480;
    func_8002F260(D_80068330, D_8005A840, 0x50);
    D_8005A83C = 3;
    D_8005A82C = 320;
    func_80010CE8();
    func_800351A0(1);
    D_800661C8 = 0;
    D_800F2740 = D_8005A826;
    D_800F2742 = D_8005A82A;
}
