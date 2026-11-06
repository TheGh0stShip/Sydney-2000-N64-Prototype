/* Event-bank sound cue dispatch on game mode (link VRAM 0x80075F08), ROM 0x951B8..0x95384. */
typedef int s32;

typedef struct {
    char pad0[0xA00];
    s32 mode;
    s32 sub;
} GameState;

extern GameState *D_800FC270;
extern char D_800F3BC0[];
extern void *const D_800713F8[];
extern void func_800C0110(void *, s32, s32, s32);

void func_800951B8(void)
{
    static void *const unused_tbl[] = { &&C0, &&C1, &&C2, &&C4, &&C5, &&C6, &&END };
    unsigned int m = D_800FC270->mode;

    if (m >= 7) goto END;
    goto *D_800713F8[m];
C5:
    if (D_800FC270->sub != 0) {
        func_800C0110(D_800F3BC0, 27, 0x300, 0);
    }
    goto END;
C4:
    {
    s32 v = D_800FC270->sub;
    if (v != 1) {
        if (v != 5) goto END;
        func_800C0110(D_800F3BC0, 497, 0x300, 0);
        if (D_800FC270->sub == 0) goto END;
        func_800C0110(D_800F3BC0, 115, 0x300, 0);
        if (D_800FC270->sub == 0) goto END;
        func_800C0110(D_800F3BC0, 499, 0x300, 0);
    } else {
        func_800C0110(D_800F3BC0, 498, 0x300, 0);
        if (D_800FC270->sub == 0) goto END;
        func_800C0110(D_800F3BC0, 115, 0x300, 0);
        if (D_800FC270->sub == 0) goto END;
        func_800C0110(D_800F3BC0, 500, 0x300, 0);
    }
    }
    goto END;
C0:
    if (D_800FC270->sub == 1) {
        func_800C0110(D_800F3BC0, 185, 0x300, 0);
    }
    goto END;
C1:
    if (D_800FC270->sub == 1) {
        func_800C0110(D_800F3BC0, 187, 0x300, 0);
    }
    goto END;
C2:
    if (D_800FC270->sub == 1) {
        func_800C0110(D_800F3BC0, 189, 0x300, 0);
    }
    goto END;
C6:
    if (D_800FC270->sub != 0) {
        func_800C0110(D_800F3BC0, 28, 0x300, 0);
    }
END:;
}
