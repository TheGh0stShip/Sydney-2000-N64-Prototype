/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075F08\n.ent func_80075F08\n"
    "func_80075F08:\n"
    ".word 0x14600035\n"
    "addiu $19,$2,10072\n"
    "move $4,$19\n"
    "addiu $5,$16,360\n"
    "li $6,120\n"
    "lui $7,0x8007\n"
    ".end func_80075F08\n.set at\n.set reorder\n");
