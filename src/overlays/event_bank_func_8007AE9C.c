/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AE9C\n.ent func_8007AE9C\n"
    "func_8007AE9C:\n"
    "move $4,$19\n"
    "move $5,$21\n"
    "jal func_80071610\n"
    "addiu $6,$29,24\n"
    "j func_80072930\n"
    "nop\n"
    ".end func_8007AE9C\n.set at\n.set reorder\n");
