/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076758\n.ent func_80076758\n"
    "func_80076758:\n"
    ".word 0x5440000B\n"
    "sw $5,1552($19)\n"
    "lui $2,0x8010\n"
    "lw $4,-15760($2)\n"
    "lw $3,2560($4)\n"
    ".end func_80076758\n.set at\n.set reorder\n");
