/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007AF48\n.ent func_8007AF48\n"
    "func_8007AF48:\n"
    "sltu $2,$2,$3\n"
    ".word 0x1440FFF1\n"
    ".end func_8007AF48\n.set at\n.set reorder\n");
