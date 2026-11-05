/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A1070\n.ent func_800A1070\n"
    "func_800A1070:\n"
    "lb $6,24038($16)\n"
    "jal func_8009B80C\n"
    "li $7,2\n"
    "j func_800752F0\n"
    "nop\n"
    ".end func_800A1070\n.set at\n.set reorder\n");
