extern unsigned char D_800F1AE0[];
extern char *D_800F2660;
extern int func_8001D4B8(void *bank, int id, int a, int b);
extern void func_8001D640(void *bank, int handle, int volume);
extern void func_800E97D4(int, int);
extern void func_800B1550(void *, int);

void func_800B1AB8(void *self, unsigned char *input)
{
    int handle;

    if (input[3] & 0x10) {
        handle = func_8001D4B8(D_800F1AE0, 130, 0, 1);
        func_8001D640(D_800F1AE0, handle, (int)((long long)*(int *)(D_800F1AE0 + 104) * 32767) >> 15);
        func_800E97D4(*(int *)(D_800F2660 + 4), 300);
    } else {
        func_800B1550(self, input[0]);
    }
}
