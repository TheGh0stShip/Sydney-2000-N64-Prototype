typedef struct {
    unsigned char v[4];
} Bytes4;

extern Bytes4 D_80070800;
extern void func_8008393C(void *obj, int id, void *out);

void func_800C3C7C(char *obj, unsigned char sel, int add)
{
    Bytes4 tbl;
    unsigned char idx;
    signed char *rec;

    tbl = D_80070800;
    idx = tbl.v[sel] + add;
    *(int *)(obj + 17128) = 0;
    func_8008393C(obj, 9, obj + 17128);
    *(signed char **)(obj + 17124) = *(signed char **)(obj + 17128) + idx * 46;
    *(int *)(obj + 3856) = (*(signed char **)(obj + 17124))[0] * 7680;
    rec = *(signed char **)(obj + 17124);
    *(unsigned char *)(obj + 19372) = rec[1];
    *(short *)(obj + 19320) = rec[2];
    *(short *)(obj + 19300) = rec[3];
    *(short *)(obj + 19302) = rec[4];
    *(short *)(obj + 19304) = rec[5];
}
