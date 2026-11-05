/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CEF00\n.ent func_800CEF00\n"
    "func_800CEF00:\n"
    "addiu $29,$29,-32\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $17,20($29)\n"
    "move $17,$5\n"
    "lui $2,0x8007\n"
    "addiu $2,$2,2296\n"
    ".end func_800CEF00\n.set at\n.set reorder\n");
