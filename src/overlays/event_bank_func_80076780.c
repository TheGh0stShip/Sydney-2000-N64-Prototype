/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076780\n.ent func_80076780\n"
    "func_80076780:\n"
    "beql $2,$0,L_80076788\n"
    "sw $5,1552($19)\n"
    "L_80076788:\n"
    "lbu $4,1556($19)\n"
    "jal func_8009BB88\n"
    "li $5,1\n"
    "lui $4,0x8004\n"
    "addiu $16,$4,17904\n"
    "lw $3,8($16)\n"
    "li $2,1\n"
    ".word 0x1462000B\n"
    "nop\n"
    "lw $2,4($16)\n"
    ".end func_80076780\n.set at\n.set reorder\n");
