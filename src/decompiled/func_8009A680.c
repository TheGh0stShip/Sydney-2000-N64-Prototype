#include "sydney_types.h"

/* Load save block `slot`; if missing or bad magic, allocate a fresh one and reset its tables. */
typedef struct { s16 unk_0, unk_2, unk_4, unk_6; s32 unk_8; } Entry;
typedef struct { u32 magic; Entry a[32]; Entry b[3]; Entry c[6]; } Save;
extern char *D_800F16D0[];
extern Save *D_800F165C;
extern Entry *D_800F1660;
extern Entry *D_800F1664;
extern Entry *D_800F1668;
extern u8 D_800F2758[];
extern char D_800845AC[];
extern char D_800845B4[];
extern char D_800845E4[];
s32 func_80005A3C(char *, Save **, void *, s32);
void func_800AA658(void *, Save **);
s32 func_800AA804(void *, Save **, s32, char *);
void func_800AAA60(char *, s32, char *);
void func_8009A680(s32 slot) {
    u32 i;
    Entry *e;
    Entry *p;
    if (func_80005A3C(D_800F16D0[slot], &D_800F165C, D_800F2758, 1) != 0 && D_800F165C != NULL) {
        if ((D_800F165C->magic & ~0xFF) == 0x53543200) {
            D_800F1660 = D_800F165C->a;
            D_800F1664 = D_800F165C->b;
            D_800F1668 = D_800F165C->c;
            return;
        }
    }
    if (D_800F165C != NULL) func_800AA658(D_800F2758, &D_800F165C);
    if (func_800AA804(D_800F2758, &D_800F165C, sizeof(Save), D_800845AC) != 0) {
        func_800AAA60(D_800845B4, 0xEE, D_800845E4);
    }
    e = D_800F1660 = D_800F165C->a;
    D_800F1664 = D_800F165C->b;
    D_800F1668 = D_800F165C->c;
    for (i = 0; i < 32; e++, i++) {
        e->unk_0 = 1000; e->unk_2 = 1000; e->unk_4 = 1000; e->unk_6 = 1000; e->unk_8 = 0;
    }
    for (i = 0, p = D_800F1664; i < 3; p++, i++) {
        p->unk_0 = 0; p->unk_2 = 0; p->unk_4 = 0; p->unk_6 = 0; p->unk_8 = 0;
    }
    for (i = 0, p = D_800F1668; i < 6; p++, i++) {
        p->unk_0 = 0; p->unk_2 = 0; p->unk_4 = 0; p->unk_6 = 0; p->unk_8 = 0;
    }
}
