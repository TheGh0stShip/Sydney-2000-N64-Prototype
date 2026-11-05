/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC9B8\n.ent func_800AC9B8\n"
    "func_800AC9B8:\n"
    "lw $2,11704($18)\n"
    "lbu $4,32($3)\n"
    "j func_80074CBC\n"
    "sw $2,72($3)\n"
    ".end func_800AC9B8\n.set at\n.set reorder\n");
