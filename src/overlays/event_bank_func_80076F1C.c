/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076F1C\n.ent func_80076F1C\n"
    "func_80076F1C:\n"
    "lui $7,0x7fff\n"
    "lw $4,5104($6)\n"
    ".end func_80076F1C\n.set at\n.set reorder\n");
