typedef struct { signed char b[60]; } Slot;
typedef struct { char pad[16]; Slot s[8]; char pad2[500-16-480]; signed char c[8]; } Tbl;
extern void func_800C4738(void);
extern Tbl *D_800FC270;

/* Reset the per-slot state bytes (slot stride 60, state at +76) and the 8 status bytes at +500. */
void func_800B1A54(void)
{
    unsigned char i;

    func_800C4738();
    for (i = 0; i < 8; i++) {
        D_800FC270->s[i].b[60] = -1;
        D_800FC270->c[i] = -1;
    }
}
