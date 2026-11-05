/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800726F8\n.ent func_800726F8\n"
    "func_800726F8:\n"
    "addu $2,$2,$30\n"
    "lw $5,0($2)\n"
    "j func_80072C74\n"
    "li $6,-1\n"
    ".end func_800726F8\n.set at\n.set reorder\n");
