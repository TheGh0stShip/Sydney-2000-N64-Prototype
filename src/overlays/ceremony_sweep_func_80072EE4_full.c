/* Ceremony event handler (link VRAM 0x80071770), ROM 0x6B5C0..0x6B7F4. */
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    u32 arg;
} Event;

extern u32 D_800F2714;
extern s32 D_800F2744;
extern char D_800F26E0[];
extern void *D_800713D0[];
extern void *D_80071400[];

extern void func_800B4794(s32);
extern void func_800719A4(u8 *);
extern void func_80072F4C(u8 *);
extern void func_800BC07C(u8 *, s32);
extern void func_80072A38(u8 *);
extern void func_800AB2A4(char *, s32, s32, s32, u8 *, s32);
extern void func_80073F50(u8 *, void *, s32);
extern void func_80073D28(u8 *);
extern void func_800A9B78(u8 *, u8 *, s32, s32, s32);

#define W(o) (*(s32 *)(obj + (o)))

void func_80072EE4(u8 *obj, Event *evt)
{
    static void *const unused_tbl[] = { &&L_12, &&L_3, &&L_5, &&L_7, &&L_11,
                                        &&S_1, &&S_2, &&S_4, &&S_5, &&S_8, &&L_end };
    u32 i;
    u8 *sub;
    u32 r;

    i = evt->type - 1;
    if (i >= 11) {
        goto L_end;
    }
    goto *D_800713D0[i];
L_3:
    func_800B4794(1);
    func_800719A4(obj);
    func_800B4794(0);
    goto L_end;
L_5:
    if (W(0x1F0) != 0) {
        func_80072F4C(obj);
    }
    goto L_end;
L_12:
    sub = obj + 0x33C;
    func_800BC07C(sub, ((u8 *)&evt->arg)[1]);
    if (sub[3] == 0) {
        goto L_end;
    }
L_7:
    func_80072A38(obj);
    {
        s32 w = W(4);
        func_800AB2A4(D_800F26E0, D_800F2744, 20, w, obj, 15);
    }
    goto L_end;
L_11:
    i = evt->arg;
    if (i >= 13) {
        goto L_end;
    }
    goto *D_80071400[i];
S_1:
    if (obj[0x2860] == 2) {
        func_80073F50(obj, *(void **)(obj + (((D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF) >> 29) << 2) + 0x5BC), 1);
        func_80073D28(obj);
        goto L_end;
    }
    if (obj[0x2860] == 7) {
        func_800A9B78(obj + 0x1234, obj + 0xACC, 1, 1, 2);
        goto L_end;
    }
    goto other;
S_2:
    if (obj[0x2860] != 2) {
        goto other;
    }
    func_80073F50(obj, obj + 0x7A4, 1);
    func_80073D28(obj);
    goto L_end;
S_4:
    if (obj[0x2860] != 2) {
        goto other;
    }
    func_80073F50(obj, obj + 0x938, 1);
    func_80073D28(obj);
    goto L_end;
S_5:
    if (obj[0x2860] != 2) {
        goto other;
    }
    func_80073F50(obj, *(void **)(obj + (((D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF) >> 29) << 2) + 0x5BC), 1);
    func_80073D28(obj);
    goto L_end;
other:
    func_80073F50(obj, obj + 0xACC, 1);
    goto L_end;
S_8:
    func_800A9B78(obj + 0x1234, obj + 0xC60, 1, 1, 2);
L_end:
    W(0x10) = evt->time;
}
