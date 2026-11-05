/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E7534\n.ent func_800E7534\n"
    "func_800E7534:\n"
    "lhu $2,24($5)\n"
    "lw $3,28($5)\n"
    "sll $2,$2,0x2\n"
    "addu $4,$4,$2\n"
    "sll $3,$3,0x2\n"
    "lw $2,4($4)\n"
    "addiu $3,$3,20\n"
    "addu $2,$2,$3\n"
    "jr $31\n"
    "sw $2,40($5)\n"
    ".end func_800E7534\n.set at\n.set reorder\n");
