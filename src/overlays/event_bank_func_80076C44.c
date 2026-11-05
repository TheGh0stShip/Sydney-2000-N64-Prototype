/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076C44\n.ent func_80076C44\n"
    "func_80076C44:\n"
    "addiu $4,$18,1584\n"
    "lw $2,736($4)\n"
    "beql $2,$0,L_80076C60\n"
    "addiu $4,$18,28608\n"
    "jal func_8008382C\n"
    "nop\n"
    "addiu $4,$18,28608\n"
    "L_80076C60:\n"
    "lw $2,736($4)\n"
    ".end func_80076C44\n.set at\n.set reorder\n");
