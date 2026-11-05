/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E5E84\n.ent func_800E5E84\n"
    "func_800E5E84:\n"
    "sll $2,$2,0x2\n"
    "sll $3,$3,0x3\n"
    "addu $2,$2,$3\n"
    "addu $2,$10,$2\n"
    "lui $3,0x1\n"
    "addu $2,$2,$3\n"
    "swc1 $f0,3368($2)\n"
    "li $2,1\n"
    "sw $2,2768($9)\n"
    "jr $31\n"
    "nop\n"
    ".end func_800E5E84\n.set at\n.set reorder\n");
