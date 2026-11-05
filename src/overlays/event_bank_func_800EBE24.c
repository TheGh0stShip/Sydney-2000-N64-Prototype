/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800EBE24\n.ent func_800EBE24\n"
    "func_800EBE24:\n"
    "sb $0,1($2)\n"
    "sb $0,2($2)\n"
    ".end func_800EBE24\n.set at\n.set reorder\n");
