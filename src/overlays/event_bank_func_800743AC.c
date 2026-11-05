/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800743AC\n.ent func_800743AC\n"
    "func_800743AC:\n"
    "sw $21,3388($2)\n"
    "lbu $3,1556($18)\n"
    "addiu $2,$3,-3\n"
    "sltiu $2,$2,2\n"
    ".word 0x144000F6\n"
    ".end func_800743AC\n.set at\n.set reorder\n");
