/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800770C4\n.ent func_800770C4\n"
    "func_800770C4:\n"
    "sll $2,$7,0x2\n"
    "addu $3,$3,$2\n"
    "negu $2,$5\n"
    "j func_80073D90\n"
    "sw $2,0($3)\n"
    ".end func_800770C4\n.set at\n.set reorder\n");
