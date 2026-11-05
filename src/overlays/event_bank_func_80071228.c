/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071228\n.ent func_80071228\n"
    "func_80071228:\n"
    "sb $0,4000($21)\n"
    "li $2,1\n"
    "sb $2,4000($21)\n"
    "lw $2,192($21)\n"
    "beqz $2,L_80071244\n"
    "li $2,1\n"
    "sb $2,4000($21)\n"
    "L_80071244:\n"
    ".end func_80071228\n.set at\n.set reorder\n");
