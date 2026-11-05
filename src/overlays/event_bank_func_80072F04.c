/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072F04\n.ent func_80072F04\n"
    "func_80072F04:\n"
    "and $2,$2,$20\n"
    "sw $2,10004($17)\n"
    "srl $2,$2,0x1c\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$8\n"
    ".end func_80072F04\n.set at\n.set reorder\n");
