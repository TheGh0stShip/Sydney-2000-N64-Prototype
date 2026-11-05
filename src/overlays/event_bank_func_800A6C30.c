/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A6C30\n.ent func_800A6C30\n"
    "func_800A6C30:\n"
    "lbu $2,31919($17)\n"
    "addiu $2,$2,-3\n"
    "sltiu $2,$2,2\n"
    ".word 0x14400071\n"
    ".end func_800A6C30\n.set at\n.set reorder\n");
