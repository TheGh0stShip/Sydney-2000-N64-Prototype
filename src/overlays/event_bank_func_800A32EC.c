/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A32EC\n.ent func_800A32EC\n"
    "func_800A32EC:\n"
    "addiu $3,$3,-1\n"
    "sltiu $2,$3,25\n"
    ".word 0x10400187\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,4272\n"
    "sll $3,$3,0x2\n"
    "addu $3,$3,$2\n"
    "lw $2,0($3)\n"
    "jr $2\n"
    "nop\n"
    ".end func_800A32EC\n.set at\n.set reorder\n");
