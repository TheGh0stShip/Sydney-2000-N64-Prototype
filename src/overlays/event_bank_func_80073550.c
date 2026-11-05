/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80073550\n.ent func_80073550\n"
    "func_80073550:\n"
    "addiu $2,$17,1724\n"
    ".word 0x5040000F\n"
    "addiu $2,$17,1088\n"
    "addiu $16,$17,2936\n"
    ".word 0x5050000C\n"
    "addiu $2,$17,1088\n"
    ".end func_80073550\n.set at\n.set reorder\n");
