/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076390\n.ent func_80076390\n"
    "func_80076390:\n"
    "lw $4,184($18)\n"
    "jal func_80017B24\n"
    "nop\n"
    "lbu $2,1556($18)\n"
    "addiu $2,$2,-2\n"
    "sltiu $2,$2,3\n"
    ".word 0x14400009\n"
    "addiu $3,$18,628\n"
    "lw $2,808($18)\n"
    ".end func_80076390\n.set at\n.set reorder\n");
