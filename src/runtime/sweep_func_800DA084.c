typedef struct Bucket {
    unsigned short count;
    signed char ids[8];
} Bucket;

typedef struct Slot {
    signed char id;
    unsigned char kind;
    short timer;
    float scale;
    signed char link;
    unsigned char pad9;
    unsigned char flag;
    unsigned char pad11;
} Slot;

typedef struct Entrant {
    unsigned char pad0[28];
    unsigned char kind;
    unsigned char pad29[31];
} Entrant;

typedef struct Game {
    Entrant entrants[1];
    unsigned char pad[0x9F8 - 60];
    int mode9F8;
    int pad9FC;
    int modeA00;
    int padA04;
    int seedA08;
    unsigned char groups;
    unsigned char perGroup;
    unsigned char padA0E[2];
    Slot slots[1];
} Game;

extern Game *D_800FC270;
extern unsigned char D_80103420[];
extern unsigned char D_80103428;
extern Bucket D_801032F0[];
extern unsigned int D_800F2714;
extern unsigned char func_800D9E3C(int *seed);

void func_800DA084(void) {
    Bucket buckets[8];
    Bucket *b;
    Bucket *src;
    Bucket *s2;
    Slot *row;
    int seed;
    unsigned char i;
    unsigned char j;
    unsigned char k;
    unsigned char slot;
    unsigned int q;
    unsigned int x;
    unsigned char id;

    seed = D_800FC270->seedA08;
    if (D_800FC270->modeA00 == 5) {
        seed |= 0x69FC50A6;
    }
    b = buckets;
    for (i = 8; i != 0; i--) {
        b->count = 0;
        for (j = 0; j < 8; j++) {
            b->ids[j] = -1;
        }
        b++;
    }
    if ((unsigned int)(D_800FC270->modeA00 - 5) < 2) {
        D_800FC270->groups = D_801032F0[D_80103420[0]].count;
    }
    k = 0;
    for (i = 0; i < D_80103428; i++) {
        src = &D_801032F0[D_80103420[i]];
        for (j = 0; j < src->count; j++) {
            while (buckets[k].count >= D_800FC270->perGroup) {
                k++;
                if (k >= D_800FC270->groups) {
                    D_800FC270->groups++;
                }
            }
            s2 = &buckets[k];
            buckets[k].ids[s2->count] = src->ids[j];
            k++;
            s2->count++;
            if (k >= D_800FC270->groups) {
                k = 0;
            }
        }
    }
    if (D_800FC270->groups == 0) {
        D_800FC270->groups = 1;
    }
    q = 32 / (int)D_800FC270->groups;
    if (q < D_800FC270->perGroup) {
        D_800FC270->perGroup = q;
    }
    row = D_800FC270->slots;
    for (i = D_800FC270->groups * D_800FC270->perGroup; i != 0; i--) {
        row->id = -1;
        row++;
    }
    i = 0;
    row = D_800FC270->slots;
    while (1) {
        if (!(i < D_800FC270->groups)) break;
        if (D_800FC270->modeA00 == 5) {
            D_800FC270->seedA08 = seed;
        }
        b = &buckets[i];
        j = D_800FC270->perGroup;
        while (1) {
            if (j == 0) break;
            if (D_800FC270->mode9F8 != 10) {
                x = (D_800F2714 * 16807) & 0x7FFFFFFF;
                slot = ((x >> 15) * D_800FC270->perGroup) >> 16;
                D_800F2714 = x;
            } else {
                slot = 0;
            }
            while (row[slot].id != -1) {
                slot++;
                if (slot >= D_800FC270->perGroup) {
                    slot = 0;
                }
            }
            if (b->count != 0) {
                b->count--;
                id = b->ids[b->count];
                row[slot].id = id;
                row[slot].kind = D_800FC270->entrants[id].kind;
            } else {
                row[slot].id = 8;
                row[slot].kind = func_800D9E3C(&D_800FC270->seedA08);
            }
            j--;
            row[slot].timer = 0;
            row[slot].link = -1;
            row[slot].flag = 0;
            row[slot].scale = -1.0f;
        }
        i++;
        row += D_800FC270->perGroup;
    }
}
