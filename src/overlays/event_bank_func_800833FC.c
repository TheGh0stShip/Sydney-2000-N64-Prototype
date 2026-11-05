/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800833FC\n.ent func_800833FC\n"
    "func_800833FC:\n"
    "li $6,1\n"
    "swc1 $f0,24($29)\n"
    "lw $3,24($29)\n"
    "j func_8007210C\n"
    "li $7,-1\n"
    ".end func_800833FC\n.set at\n.set reorder\n");
