/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071E28\n.ent func_80071E28\n"
    "func_80071E28:\n"
    "li $18,1\n"
    "sw $18,10020($2)\n"
    ".end func_80071E28\n.set at\n.set reorder\n");
