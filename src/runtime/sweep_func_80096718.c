/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80096718\n.ent func_80096718\n"
    "func_80096718:\n"
    "addiu $29,$29,-24\n"
    "lui $2,0x8008\n"
    "addiu $2,$2,16904\n"
    "andi $5,$5,0x1\n"
    "sw $31,16($29)\n"
    "beqz $5,L_8009673C\n"
    "sw $2,24($4)\n"
    "jal func_80004380\n"
    "nop\n"
    "L_8009673C:\n"
    "lw $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,24\n"
    ".end func_80096718\n.set at\n.set reorder\n");
