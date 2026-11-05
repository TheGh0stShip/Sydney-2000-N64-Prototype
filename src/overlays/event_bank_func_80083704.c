/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80083704\n.ent func_80083704\n"
    "func_80083704:\n"
    "li $2,4\n"
    "lbu $3,1557($17)\n"
    "beq $3,$2,L_8008371C\n"
    "nop\n"
    "jal func_800766AC\n"
    "move $4,$17\n"
    "L_8008371C:\n"
    "lbu $2,1557($17)\n"
    "li $16,5\n"
    ".end func_80083704\n.set at\n.set reorder\n");
