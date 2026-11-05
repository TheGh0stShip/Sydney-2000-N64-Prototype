/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AD58C\n.ent func_800AD58C\n"
    "func_800AD58C:\n"
    "jal func_800ADC54\n"
    "sllv $5,$23,$5\n"
    "j func_800757C0\n"
    "sb $23,176($16)\n"
    ".end func_800AD58C\n.set at\n.set reorder\n");
