/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D374\n.ent func_8007D374\n"
    "func_8007D374:\n"
    "move $4,$18\n"
    "addiu $5,$16,4\n"
    "li $6,2200\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    "addiu $7,$7,2008\n"
    ".word 0x14400012\n"
    "nop\n"
    "lw $2,8($16)\n"
    ".end func_8007D374\n.set at\n.set reorder\n");
