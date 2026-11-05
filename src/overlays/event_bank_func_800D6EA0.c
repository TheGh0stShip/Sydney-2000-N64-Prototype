/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D6EA0\n.ent func_800D6EA0\n"
    "func_800D6EA0:\n"
    "beq $3,$2,L_800D6EB0\n"
    "nop\n"
    "jal func_80075348\n"
    "move $4,$17\n"
    "L_800D6EB0:\n"
    "lbu $2,1557($17)\n"
    "li $16,5\n"
    ".word 0x10500006\n"
    "addiu $4,$17,12884\n"
    "lui $5,0x8007\n"
    "addiu $5,$5,29964\n"
    "move $6,$0\n"
    "jal func_800D33A0\n"
    ".end func_800D6EA0\n.set at\n.set reorder\n");
