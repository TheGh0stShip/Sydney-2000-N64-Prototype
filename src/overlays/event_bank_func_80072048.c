/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072048\n.ent func_80072048\n"
    "func_80072048:\n"
    "lw $17,76($29)\n"
    "lw $16,72($29)\n"
    "ldc1 $f22,120($29)\n"
    "ldc1 $f20,112($29)\n"
    "jr $31\n"
    "addiu $29,$29,128\n"
    ".end func_80072048\n.set at\n.set reorder\n");
