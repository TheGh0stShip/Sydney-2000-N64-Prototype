/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074300\n.ent func_80074300\n"
    "func_80074300:\n"
    "li $2,9\n"
    "sw $2,1552($18)\n"
    "move $4,$18\n"
    "li $5,56\n"
    "li $6,13\n"
    "jal func_800AC25C\n"
    "move $7,$0\n"
    "j func_80071828\n"
    "move $4,$18\n"
    ".end func_80074300\n.set at\n.set reorder\n");
