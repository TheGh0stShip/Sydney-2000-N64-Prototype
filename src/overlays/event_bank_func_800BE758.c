typedef struct {
    unsigned char v[4];
} ByteQuad;

typedef struct {
    signed char count;
    signed char frames;
    unsigned char pad[14];
} Entry;

extern ByteQuad D_80070800;
extern void func_8008393C(void *object, int kind, void *out);

void func_800BE758(unsigned char *object, unsigned char sel, int delta)
{
    ByteQuad table = D_80070800;
    unsigned char idx = table.v[sel] + delta;

    *(int *)(object + 17620) = 0;
    func_8008393C(object, 6, object + 17620);
    *(Entry **)(object + 17616) = *(Entry **)(object + 17620) + idx;
    *(int *)(object + 3856) = (*(Entry **)(object + 17616))->frames * 7680;
    *(int *)(object + 18688) = (*(Entry **)(object + 17616))->count;
}
