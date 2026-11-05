/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B728\n.ent func_8007B728\n"
    "func_8007B728:\n"
    "addu $4,$16,$4\n"
    "jal func_800ADC1C\n"
    "addiu $4,$16,272\n"
    "addu $2,$17,$19\n"
    "addu $2,$2,$20\n"
    "addu $17,$17,$20\n"
    "lw $2,180($2)\n"
    ".end func_8007B728\n.set at\n.set reorder\n");
