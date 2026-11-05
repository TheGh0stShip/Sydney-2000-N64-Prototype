/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070BC4\n.ent func_80070BC4\n"
    "func_80070BC4:\n"
    "sltiu $2,$3,12\n"
    ".word 0x1040018F\n"
    "lui $2,0x8007\n"
    ".end func_80070BC4\n.set at\n.set reorder\n");
