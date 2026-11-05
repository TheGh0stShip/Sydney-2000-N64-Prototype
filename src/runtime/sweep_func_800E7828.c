typedef struct Header {
    char pad[6];
    unsigned short count;
} Header;

typedef struct Record {
    unsigned char words;
    unsigned char parts;
    short size;
} Record;

typedef struct Bank {
    Header *header;
    Record *records[256];
    char pad[1280];
    int a;
    int b;
} Bank;

extern void *D_800FF414[];
extern char D_800F2758[];
extern void func_80005A3C(void *, Bank *, void *, int);
extern void func_800E7784(Bank *, unsigned char);

void func_800E7828(Bank *bank, int a, int b, int id)
{
    unsigned int i;
    unsigned char *p;
    Record *rec;
    int n;
    int mask;
    Record **slot;

    bank->a = a;
    bank->b = b;
    func_80005A3C(D_800FF414[(unsigned char)id], bank, D_800F2758, 1);
    i = 0;
    mask = ~1;
    slot = (Record **)bank;
    p = (unsigned char *)bank->header + 8;
next:
    if (i < bank->header->count) {
        rec = (Record *)p;
        slot[1] = rec;
        p += 732;
        n = rec->parts;
        p += rec->words * 4;
        rec->size = p - (unsigned char *)rec;
        if (n != 0) {
            do {
                p += p[4] + 6;
                n--;
                p = (unsigned char *)((int)p & mask);
            } while ((unsigned char)n != 0);
        }
        slot++;
        i++;
        goto next;
    }
    for (; i < 256; i++) {
        bank->records[i] = 0;
    }
    func_800E7784(bank, id);
}
