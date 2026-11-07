typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { s8 type; u8 label; s16 extra; s32 value; u8 index; } MenuSource;
typedef struct { s16 x; s16 y; s32 pad4; s32 flag; s32 pad12; s32 kind; s32 pad20; } MenuItem;
typedef struct { s32 id; void *icon; void *text; s32 value; } MenuRecord;
typedef struct { u8 pad[60]; } Slot;
typedef struct { u8 pad0[20]; Slot slots[42]; u8 pad1[2564 - 20 - 42 * 60]; s32 mode; } GameState;
extern MenuSource *D_800F1798[];
extern MenuItem D_800F1494[];
extern GameState *D_800FC270;
extern s32 D_80100650;
extern MenuRecord D_80100660[];
extern u8 func_800DA804(s32, s32, MenuSource **, s32, s32);
extern void *func_800D98FC(s32);
extern void func_800D7130(s32, MenuItem *, s32);
void func_8009AC98(s32 id, s32 sel, s32 target, u8 flag)
{
    u8 count;
    u8 i;
    MenuSource *src;
    MenuRecord *rec;
    void *icon;

    count = func_800DA804(sel, 1, D_800F1798, 0, 0);
    if (D_800FC270->mode == 5) {
        D_800F1494[0].kind = 695;
    } else {
        D_80100650 = sel + 1;
        if (D_800FC270->mode == 4) {
            if (id == 235) {
                D_800F1494[0].kind = 316;
            } else {
                D_800F1494[0].kind = 696;
            }
        } else {
            D_800F1494[0].kind = 697;
        }
    }
    D_800F1494[0].flag = flag;
    i = 0;
    while (1) {
        if (!(i < count))
            break;
        rec = &D_80100660[i];
        src = D_800F1798[i];
        src->index = i;
        if (src->type != 8) {
            icon = &D_800FC270->slots[src->type];
        } else {
            icon = func_800D98FC(13);
        }
        rec->id = i + 1;
        rec->icon = icon;
        rec->text = func_800D98FC(src->label + 149);
        if (src->extra != -1) {
            rec->value = src->value;
            D_800F1494[i + 1].kind = 246;
        } else {
            D_800F1494[i + 1].kind = 245;
        }
        D_800F1494[i + 1].y = i * 20 + 30;
        D_800F1494[i + 1].flag = flag;
        i++;
    }
    func_800D7130(target, D_800F1494, count + 1);
}
