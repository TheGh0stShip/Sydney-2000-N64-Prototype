typedef struct { int time; int duration; } Entry;
typedef struct { char pad0[0x615]; unsigned char mode; char pad616[0x615C - 0x616]; int offset; } State;
typedef struct {
    char pad0[4]; State *state; char pad8[0x27C - 8]; unsigned char row;
    unsigned char index; unsigned short value; int next;
    char pad284[0x2DE - 0x284]; unsigned char jitter;
    char pad2df[0x4D4 - 0x2DF]; unsigned short initial;
} Obj;
extern int D_800F2778;
extern unsigned int D_800F2C14;
extern Entry D_8007BBB0[][4];
extern Entry D_8007BA00[];
int func_80079E80(Obj *obj, int t)
{
    State *state = obj->state; Entry *entry; int d; int off;
    t -= D_800F2778;
    if (t >= 0) {
    if (state->mode != 2) entry = &D_8007BBB0[obj->row][obj->index];
    else entry = &D_8007BA00[obj->index];
    off = state->offset;
    if (entry->time + off < t) { entry++; obj->next = t; obj->index++; }
    if (t >= obj->next) {
    if (obj->value != 0) obj->value ^= 3;
    else obj->value = obj->initial;
    d = entry->duration;
    if (obj->jitter != 0) {
        unsigned int s;
        s = (D_800F2C14 * 16807) & 0x7FFFFFFF;
        d += (unsigned int)(d * (((s >> 15) * obj->jitter) >> 16)) / 100;
        D_800F2C14 = s;
    }
    obj->next += d;
    }
    return obj->value;
    }
    return 0;
}
