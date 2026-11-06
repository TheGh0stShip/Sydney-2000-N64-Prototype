/* event_bank ROM 0x7ABD4 (link 0x80071944): menu event dispatch.
 * 22-entry jump table D_80070F98 lives in overlay rodata (ROM 0x7A228). */
typedef struct {
    int pad[4];
    unsigned int kind;
} Event;

extern void *D_80070F98[];
extern void func_80077F28(char *ctx, int arg, int flag);
extern void func_800A9B78(char *a, char *b, int c, int d, int e);

void func_8007ABD4(char *ctx, Event *ev)
{
    static void *const unused_tbl[] = { &&c1, &&c6, &&c7, &&c13, &&c15, &&out };
    unsigned int k = ev->kind;

    if (k >= 22) {
        goto out;
    }
    goto *D_80070F98[k];
c1:
    func_80077F28(ctx, *(int *)(ctx + 0x536C), 1);
    goto out;
c6:
    func_800A9B78(ctx + 0x86F8, ctx + 0x88A8, 1, 1, 2);
    goto out;
c7:
    func_800A9B78(ctx + 0x86F8, ctx + 0x8964, 1, 1, 2);
    goto out;
c13:
    func_80077F28(ctx, *(int *)(ctx + 0x536C), 1);
    func_800A9B78(ctx + 0x86F8, ctx + 0x88A8, 1, 1, 1);
    goto out;
c15:
    func_800A9B78(ctx + 0x86F8, ctx + 0x8964, 1, 1, 0);
    func_800A9B78(ctx + 0x86F8, ctx + 0x88A8, 1, 1, 1);
out:
    ;
}
