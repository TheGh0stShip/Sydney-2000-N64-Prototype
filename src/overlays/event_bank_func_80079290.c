/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80079290\n.ent func_80079290\n"
    "func_80079290:\n"
    "addiu $29,$29,-16\n"
    "lui $2,0x1\n"
    "addu $4,$4,$2\n"
    "li $2,1\n"
    "sw $2,3404($4)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".end func_80079290\n.set at\n.set reorder\n");
