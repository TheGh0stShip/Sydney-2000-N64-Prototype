/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A6334\n.ent func_800A6334\n"
    "func_800A6334:\n"
    ".word 0x12420032\n"
    "nop\n"
    "lbu $2,31919($19)\n"
    "addiu $2,$2,-3\n"
    "sltiu $2,$2,2\n"
    ".word 0x1440002D\n"
    "addu $5,$18,$20\n"
    "lui $4,0x800f\n"
    "j func_800753F4\n"
    "addiu $4,$4,15296\n"
    ".end func_800A6334\n.set at\n.set reorder\n");
