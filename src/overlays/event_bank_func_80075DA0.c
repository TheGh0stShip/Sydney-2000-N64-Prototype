/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075DA0\n.ent func_80075DA0\n"
    "func_80075DA0:\n"
    "lw $2,12($16)\n"
    "addiu $17,$17,-1\n"
    "sw $4,0($2)\n"
    "addiu $4,$4,220\n"
    "lw $2,12($16)\n"
    ".end func_80075DA0\n.set at\n.set reorder\n");
