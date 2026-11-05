/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008382C\n.ent func_8008382C\n"
    "func_8008382C:\n"
    "addiu $4,$16,1116\n"
    "jal func_800A9BE8\n"
    "li $5,9\n"
    "lui $2,0x1\n"
    "ori $2,$2,0xc200\n"
    "sw $2,21540($16)\n"
    "li $2,33\n"
    ".end func_8008382C\n.set at\n.set reorder\n");
