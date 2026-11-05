typedef struct Item {
    char data[212];
} Item;

typedef struct PoolInfo {
    char pad[8];
    unsigned int count;
} PoolInfo;

typedef struct Owner {
    char pad[196];
    char timerA[44];
    char timerB[44];
    char timerC[44];
    unsigned short mode;
    char pad2[106];
    Item *listA[10];
    PoolInfo *infoA;
    char pad3[212];
    Item *listB[9];
    PoolInfo *infoB;
    Item *extra;
    char pad4[4];
    char sub[212];
    void *handle;
    char modeA[480];
    char modeB[4];
} Owner;

extern char D_800F2758[];
extern void func_800A6334(void *object);
extern void func_8008DB60(void *object);
extern void func_800AC308(void *object);
extern void func_800ADE84(void *object, int mode);
extern void func_800AA658(void *pool, void *slot);
extern void func_80006A18(void *object);
extern void func_8001A248(void *handle);
extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);

void func_801170E0(Owner *self)
{
    unsigned short i;
    unsigned short j;

    func_800A6334(self);
    if (self->mode == 8) {
        func_8008DB60(self->modeA);
    }
    if (self->mode == 7) {
        func_8008DB60(self->modeB);
        if (self->mode == 7) {
            for (i = 0; i < 10; i++) {
                if (self->infoA != 0) {
                    for (j = 0; j < self->infoA->count; j++) {
                        func_800AC308(&self->listA[i][j]);
                        func_800ADE84(&self->listA[i][j], 2);
                    }
                    func_800AA658(D_800F2758, &self->listA[i]);
                }
            }
            for (i = 0; i < 9; i++) {
                if (self->infoB != 0) {
                    for (j = 0; j < self->infoB->count; j++) {
                        func_800AC308(&self->listB[i][j]);
                        func_800ADE84(&self->listB[i][j], 2);
                    }
                    func_800AA658(D_800F2758, &self->listB[i]);
                }
            }
        }
    }
    if (self->extra != 0) {
        func_800ADE84(self->extra, 2);
        func_800AA658(D_800F2758, &self->extra);
    }
    func_80006A18(self->timerA);
    func_80006A18(self->timerB);
    func_80006A18(self->timerC);
    func_8001A248(&self->handle);
    func_800AC334(self->sub);
    func_800ADC1C(self->sub);
}
