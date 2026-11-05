/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CA634\n.ent func_800CA634\n"
    "func_800CA634:\n"
    "sb $2,18180($18)\n"
    "trunc.w.s $f4,$f2\n"
    "mfc1 $2,$f4\n"
    "addu $3,$3,$2\n"
    "sw $3,18220($18)\n"
    "addiu $4,$18,4552\n"
    "addiu $5,$29,24\n"
    "addiu $6,$29,56\n"
    "jal func_800B9964\n"
    "addiu $7,$29,40\n"
    "j func_80071EC8\n"
    "nop\n"
    ".end func_800CA634\n.set at\n.set reorder\n");
