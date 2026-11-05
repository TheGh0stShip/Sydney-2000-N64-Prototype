/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80074D80\n.ent func_80074D80\n"
    "func_80074D80:\n"
    "lw $2,-15760($2)\n"
    "lw $3,2560($2)\n"
    "li $2,4\n"
    ".word 0x1462001C\n"
    "li $2,5\n"
    "lbu $3,1556($18)\n"
    ".word 0x1062001A\n"
    "lui $2,0x1\n"
    "addu $16,$18,$2\n"
    "lbu $2,2821($16)\n"
    ".word 0x1440000B\n"
    "nop\n"
    ".end func_80074D80\n.set at\n.set reorder\n");
