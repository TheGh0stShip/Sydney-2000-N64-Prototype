/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3194\n.ent func_800A3194\n"
    "func_800A3194:\n"
    "lbu $3,426($2)\n"
    "li $2,1\n"
    ".word 0x14620029\n"
    "li $2,2\n"
    "lbu $2,31918($17)\n"
    "addiu $3,$2,-1\n"
    "sltiu $2,$3,14\n"
    ".word 0x10400036\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,4216\n"
    ".end func_800A3194\n.set at\n.set reorder\n");
