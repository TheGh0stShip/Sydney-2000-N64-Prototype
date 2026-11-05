/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A32EC\n.ent func_800A32EC\n"
    "func_800A32EC:\n"
    "li $2,19660\n"
    "sw $2,28($4)\n"
    "li $2,29490\n"
    "sw $2,32($4)\n"
    "li $2,32767\n"
    "sw $2,36($4)\n"
    "jr $31\n"
    "li $2,1\n"
    ".end func_800A32EC\n.set at\n.set reorder\n");
