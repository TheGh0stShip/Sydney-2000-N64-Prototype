#define D_80070A28 (*(float *)0x80070A28)
typedef struct {
    unsigned char v[4];
} ByteQuad;

typedef struct {
    float scale;
    signed char count;
    unsigned char pad[15];
} Entry;

extern ByteQuad D_80070800;
extern void func_8008393C(void *object, int kind, void *out);

void func_800BCCDC(unsigned char *object, unsigned char sel, int delta)
{
    ByteQuad table = D_80070800;
    unsigned char idx = table.v[sel] + delta;

    *(int *)(object + 17128) = 0;
    func_8008393C(object, 5, object + 17128);
    {
        float rate = D_80070A28;
        Entry *entry = *(Entry **)(object + 17128) + idx;

        *(Entry **)(object + 17124) = entry;
        *(int *)(object + 17556) = entry->count;
        *(int *)(object + 17564) = (int)(entry->scale * rate);
    }
}
