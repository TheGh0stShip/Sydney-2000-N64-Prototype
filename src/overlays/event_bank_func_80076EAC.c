/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076EAC\n.ent func_80076EAC\n"
    "func_80076EAC:\n"
    "sltiu $2,$2,2\n"
    ".word 0x144000BC\n"
    "move $19,$11\n"
    ".end func_80076EAC\n.set at\n.set reorder\n");
