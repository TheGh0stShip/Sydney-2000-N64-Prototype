typedef unsigned char u8;
typedef struct Info { char pad[744]; int unk2E8; char pad2EC[4]; int unk2F0; } Info;
typedef struct Sub { char pad[184]; u8 b0; u8 b1; u8 b2; u8 b3; } Sub;
typedef struct Obj {
    char pad[12112];
    void *unk2F50;
    char pad2F54[23004 - 12116];
    Info *info;
    Sub sub;
    char pad5A9C[24364 - 23008 - sizeof(Sub)];
    int unk5F2C;
    char pad5F30[26356 - 24368];
    char unk66F4[31844 - 26356];
    char unk7C64[0x8416 - 31844];
    u8 state;
    char pad8417[0x8428 - 0x8417];
    int unk8428;
    int unk842C;
} Obj;
extern char D_800F26E0[];
extern int D_800F2744;
extern void func_800ADC1C(void *);
extern void func_800CEE04(void *);
extern void func_800AB2A4(void *, int, int, void *, int, int);
extern void func_80076CA8(Obj *);
extern void func_800758F0(Obj *);
void func_800722AC(Obj *o)
{
    int flag;
    if (o->state != 15) {
        func_800ADC1C(o->unk66F4);
        func_800CEE04(o->unk7C64);
        o->unk8428 = 7680;
        o->unk842C = 1536;
        o->state = 11;
        flag = (o->unk5F2C == 0 || o->info->unk2E8 == 0);
        if (flag) {
            func_800AB2A4(D_800F26E0, D_800F2744, 17, o->unk2F50, 0, 0);
        }
        if (o->info->unk2F0 == 0) {
            if (o->unk5F2C == 0) {
                func_80076CA8(o);
            } else {
                func_800758F0(o);
            }
        }
        {
            Sub *s = &o->sub;
            s->b1 = 0;
            s->b0 = 1;
            s->b2 = 0;
            s->b3 = 0;
        }
    }
}
