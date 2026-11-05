/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076E7C\n.ent func_80076E7C\n"
    "func_80076E7C:\n"
    "addiu $29,$29,-56\n"
    "sw $18,40($29)\n"
    "move $18,$4\n"
    "move $11,$5\n"
    "move $12,$6\n"
    "sw $31,52($29)\n"
    "sw $20,48($29)\n"
    ".end func_80076E7C\n.set at\n.set reorder\n");
