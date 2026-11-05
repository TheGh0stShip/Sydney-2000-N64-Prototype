/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E792C\n.ent func_800E792C\n"
    "func_800E792C:\n"
    "addiu $29,$29,-24\n"
    "move $5,$4\n"
    "lui $4,0x800f\n"
    "sw $31,16($29)\n"
    "jal func_800AA658\n"
    "addiu $4,$4,10072\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800E792C\n.set at\n.set reorder\n");
