/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CC418\n.ent func_800CC418\n"
    "func_800CC418:\n"
    "addiu $29,$29,-24\n"
    "sw $16,16($29)\n"
    "sw $31,20($29)\n"
    "jal func_800CC390\n"
    "move $16,$4\n"
    "lbu $2,1927($16)\n"
    "ori $2,$2,0x4\n"
    "sb $2,1927($16)\n"
    "lw $31,20($29)\n"
    "lw $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_800CC418\n.set at\n.set reorder\n");
