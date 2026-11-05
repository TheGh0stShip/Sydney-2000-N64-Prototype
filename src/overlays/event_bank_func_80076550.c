/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076550\n.ent func_80076550\n"
    "func_80076550:\n"
    ".word 0x10A0000A\n"
    "addu $4,$4,$2\n"
    "addiu $3,$4,2\n"
    "sb $21,6($3)\n"
    ".end func_80076550\n.set at\n.set reorder\n");
