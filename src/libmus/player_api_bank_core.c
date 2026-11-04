/* Bank and handle operations preserved by the upstream libmus source. */

extern void *D_803AD9A8;
extern int D_803AD99C;
extern int D_803AD9A0;
extern int D_803AD9A4;
extern int func_800FD2A0(void *bank);

typedef struct {
    unsigned char type;
    int value;
} mus_msg_t;

extern int player_text_1AE0(mus_msg_t *msg);

void func_800FBB34(void *bank)
{
    func_800FD2A0(bank);
    if (D_803AD99C == 0)
        D_803AD99C = (int)bank;
}

int MusHandleUnPause(int handle)
{
    mus_msg_t msg;

    msg.type = 1;
    msg.value = handle;
    return player_text_1AE0(&msg);
}

void func_800FBCA0(int a)
{
    int result;
    mus_msg_t msg;

    result = 1;
    if (a == 0) {
        int type = D_803AD9A4;
        msg.type = 2;
        msg.value = type;
        D_803AD9A4 = type;
        result = player_text_1AE0(&msg);
    }
    if (result)
        D_803AD9A0 = a;
}

typedef struct {
    int count;
    int pad04[2];
    int flags;
    int pad10;
    int offset14;
    struct {
        int ptr;
        int pad;
    } wave[1];
} ptr_bank_t;

void func_800FBCFC(ptr_bank_t *b)
{
    int i;
    int base;
    ptr_bank_t *bank;

    bank = b;
    base = (int)b;
    if (!(bank->flags & 1)) {
        if (D_803AD9A8 == 0)
            D_803AD9A8 = bank;
        bank->flags = 1;
        bank->pad10 = 0;
        bank->offset14 = (int)bank + bank->offset14;
        for (i = 0; i < bank->count; i++)
            bank->wave[i].ptr = base + bank->wave[i].ptr;
    }
}
