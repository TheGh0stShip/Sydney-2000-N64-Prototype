/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E79A8\n.ent func_800E79A8\n"
    "func_800E79A8:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "move $16,$4\n"
    "sw $31,20($29)\n"
    "jal func_800E792C\n"
    "addiu $4,$16,220\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    "jal func_800AA658\n"
    "addiu $5,$16,212\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800E79A8\n.set at\n.set reorder\n");
