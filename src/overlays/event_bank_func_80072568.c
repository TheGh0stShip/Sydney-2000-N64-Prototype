/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072568\n.ent func_80072568\n"
    "func_80072568:\n"
    "sll $2,$2,0x5\n"
    "addu $2,$2,$5\n"
    "sll $3,$2,0x3\n"
    ".end func_80072568\n.set at\n.set reorder\n");
