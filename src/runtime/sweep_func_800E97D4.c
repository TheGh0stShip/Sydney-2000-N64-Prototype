/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E97D4\n.ent func_800E97D4\n"
    "func_800E97D4:\n"
    "lui $2,0x8888\n"
    "ori $2,$2,0x8889\n"
    "multu $5,$2\n"
    "mfhi $3\n"
    "srl $2,$3,0x4\n"
    "jr $31\n"
    "sh $2,27872($4)\n"
    ".end func_800E97D4\n.set at\n.set reorder\n");
