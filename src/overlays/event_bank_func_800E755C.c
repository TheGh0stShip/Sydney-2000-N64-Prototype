/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E755C\n.ent func_800E755C\n"
    "func_800E755C:\n"
    "ldc1 $f20,104($29)\n"
    "jr $31\n"
    "addiu $29,$29,112\n"
    ".end func_800E755C\n.set at\n.set reorder\n");
