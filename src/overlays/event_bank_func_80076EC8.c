/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076EC8\n.ent func_80076EC8\n"
    "func_80076EC8:\n"
    "lw $2,-15760($2)\n"
    "lw $3,2560($2)\n"
    "li $2,4\n"
    ".word 0x146200B3\n"
    "lui $2,0x1\n"
    "addu $2,$18,$2\n"
    "lbu $2,2822($2)\n"
    "sltiu $2,$2,2\n"
    ".word 0x104000AE\n"
    "nop\n"
    "jal func_80074E28\n"
    "nop\n"
    "j func_80073E44\n"
    "nop\n"
    ".end func_80076EC8\n.set at\n.set reorder\n");
