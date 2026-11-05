/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AD90\n.ent func_8007AD90\n"
    "func_8007AD90:\n"
    "addu $16,$19,$2\n"
    "lbu $2,3229($16)\n"
    "addiu $2,$2,-3\n"
    "sltiu $2,$2,2\n"
    ".word 0x104001F6\n"
    "nop\n"
    ".end func_8007AD90\n.set at\n.set reorder\n");
