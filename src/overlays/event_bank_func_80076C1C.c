/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076C1C\n.ent func_80076C1C\n"
    "func_80076C1C:\n"
    ".word 0x1440001D\n"
    "li $2,3\n"
    ".word 0x1062001B\n"
    "li $2,28\n"
    "lw $3,1552($18)\n"
    ".word 0x10620018\n"
    "move $4,$18\n"
    "li $2,1\n"
    "jal func_80075A2C\n"
    "sw $2,2832($16)\n"
    ".end func_80076C1C\n.set at\n.set reorder\n");
