/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D3990\n.ent func_800D3990\n"
    "func_800D3990:\n"
    "sw $2,19776($17)\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "lw $6,19776($17)\n"
    "jal func_80083624\n"
    "move $7,$0\n"
    "j func_80070CC8\n"
    "nop\n"
    ".end func_800D3990\n.set at\n.set reorder\n");
