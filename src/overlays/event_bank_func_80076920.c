/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076920\n.ent func_80076920\n"
    "func_80076920:\n"
    "move $19,$0\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "sw $21,44($29)\n"
    "move $21,$2\n"
    "lui $2,0x8010\n"
    "sw $22,48($29)\n"
    "move $22,$2\n"
    ".end func_80076920\n.set at\n.set reorder\n");
