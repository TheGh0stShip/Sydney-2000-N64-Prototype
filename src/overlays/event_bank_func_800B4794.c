/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B4794\n.ent func_800B4794\n"
    "func_800B4794:\n"
    "sw $9,32($29)\n"
    "addiu $11,$2,5080\n"
    "lw $8,0($11)\n"
    "lw $9,4($11)\n"
    "lw $10,8($11)\n"
    "sw $8,404($3)\n"
    "sw $9,408($3)\n"
    "sw $10,412($3)\n"
    "lw $8,12($11)\n"
    "lw $9,16($11)\n"
    "sw $8,416($3)\n"
    "sw $9,420($3)\n"
    "j func_80075610\n"
    "nop\n"
    ".end func_800B4794\n.set at\n.set reorder\n");
