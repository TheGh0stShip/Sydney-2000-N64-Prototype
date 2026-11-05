/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A3218\n.ent func_800A3218\n"
    "func_800A3218:\n"
    "sw $2,31936($17)\n"
    "li $2,12\n"
    "j func_8007228C\n"
    "sb $2,31918($17)\n"
    ".end func_800A3218\n.set at\n.set reorder\n");
