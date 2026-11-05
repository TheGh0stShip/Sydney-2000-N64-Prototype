/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B5E8\n.ent func_8007B5E8\n"
    "func_8007B5E8:\n"
    "addu $16,$19,$2\n"
    "lbu $3,3229($16)\n"
    "li $2,8\n"
    "sw $2,3220($16)\n"
    "li $2,5\n"
    ".word 0x10620008\n"
    "li $4,0x86f8\n"
    "addu $4,$19,$4\n"
    "jal func_800A9BE8\n"
    "li $5,6\n"
    "move $4,$19\n"
    ".end func_8007B5E8\n.set at\n.set reorder\n");
