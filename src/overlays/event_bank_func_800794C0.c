/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800794C0\n.ent func_800794C0\n"
    "func_800794C0:\n"
    "lui $6,0x7fff\n"
    "lbu $2,3386($16)\n"
    "lui $5,0x800f\n"
    "addiu $2,$2,1\n"
    ".end func_800794C0\n.set at\n.set reorder\n");
