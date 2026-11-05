/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076574\n.ent func_80076574\n"
    "func_80076574:\n"
    ".word 0x1440FFF9\n"
    "addiu $3,$3,12\n"
    "lbu $3,2820($17)\n"
    "move $5,$7\n"
    ".end func_80076574\n.set at\n.set reorder\n");
