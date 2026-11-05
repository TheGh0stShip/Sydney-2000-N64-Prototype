/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072920\n.ent func_80072920\n"
    "func_80072920:\n"
    "sll $2,$2,0x5\n"
    "addu $2,$2,$4\n"
    "sll $3,$2,0x3\n"
    ".end func_80072920\n.set at\n.set reorder\n");
