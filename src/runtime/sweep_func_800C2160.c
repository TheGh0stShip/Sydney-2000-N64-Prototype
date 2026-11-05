/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800C2160\n.ent func_800C2160\n"
    "func_800C2160:\n"
    "lui $2,0x800f\n"
    "lhu $3,16592($2)\n"
    ".end func_800C2160\n.set at\n.set reorder\n");
