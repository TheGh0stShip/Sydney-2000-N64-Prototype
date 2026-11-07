typedef struct { short a, b; int c; } Desc;
extern Desc D_80101850[];
void func_800BC420(void) { unsigned int i; for (i = 0; i < 29; i++) { D_80101850[i].a = -1; D_80101850[i].b = 0; } }
