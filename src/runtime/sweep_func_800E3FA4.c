typedef struct {
    unsigned char id;
    char pad[3];
} Entry;

typedef struct {
    char pad0[1264];
    unsigned short curId;
    char pad1[106];
    Entry entries[32];
} Game;

extern Game *D_800FC270;
extern char D_800F5900[];
extern void func_800E37F4(char *, unsigned int, unsigned int);
extern void func_800B31EC(int);
extern void func_800D53A0(char *, int);

void func_800E3FA4(char *obj)
{
    unsigned int i;
    int found;

    found = 0;
    for (i = 0; i < 6; i++) {
        if (D_800FC270->entries[i].id == D_800FC270->curId) {
            found = 1;
        }
        func_800E37F4(obj, i, i);
    }
    if (!found) {
        for (i = 0; i < 32; i++) {
            if (D_800FC270->entries[i].id == D_800FC270->curId) {
                break;
            }
        }
        if (i < 32) {
            func_800E37F4(obj, i, 5);
        }
    }
    func_800B31EC(0);
    func_800D53A0(D_800F5900, 20);
    *(unsigned char *)(obj + 19102) = 1;
}
