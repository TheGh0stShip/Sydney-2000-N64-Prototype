/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076710\n.ent func_80076710\n"
    "func_80076710:\n"
    "lw $5,24($17)\n"
    "addu $2,$19,$2\n"
    "sw $2,16($29)\n"
    "sw $0,20($29)\n"
    "lw $7,3236($16)\n"
    ".end func_80076710\n.set at\n.set reorder\n");
