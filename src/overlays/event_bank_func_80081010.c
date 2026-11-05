/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80081010\n.ent func_80081010\n"
    "func_80081010:\n"
    "addiu $29,$29,-168\n"
    "sw $17,156($29)\n"
    "move $17,$4\n"
    "move $4,$0\n"
    "move $5,$4\n"
    "addiu $6,$29,24\n"
    "move $7,$4\n"
    "sw $31,160($29)\n"
    ".end func_80081010\n.set at\n.set reorder\n");
