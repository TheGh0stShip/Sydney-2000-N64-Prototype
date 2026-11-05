/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070FE0\n.ent func_80070FE0\n"
    "func_80070FE0:\n"
    "li $5,7\n"
    "move $6,$5\n"
    "lw $4,188($21)\n"
    "jal func_8007E46C\n"
    "addiu $7,$21,2936\n"
    "lw $3,188($21)\n"
    "j func_800716C4\n"
    "nop\n"
    ".end func_80070FE0\n.set at\n.set reorder\n");
