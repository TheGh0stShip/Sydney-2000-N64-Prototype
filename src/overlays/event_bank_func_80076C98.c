/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076C98\n.ent func_80076C98\n"
    "func_80076C98:\n"
    "addiu $3,$2,-1\n"
    "sltiu $2,$3,28\n"
    ".word 0x1040003A\n"
    "lui $2,0x8007\n"
    ".end func_80076C98\n.set at\n.set reorder\n");
