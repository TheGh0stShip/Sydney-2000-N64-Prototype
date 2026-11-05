/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083494\n.ent func_80083494\n"
    "func_80083494:\n"
    "li $7,1\n"
    "lw $4,104($16)\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    "move $5,$2\n"
    "move $4,$16\n"
    "mflo $8\n"
    ".end func_80083494\n.set at\n.set reorder\n");
