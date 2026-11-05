/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071BA0\n.ent func_80071BA0\n"
    "func_80071BA0:\n"
    "addiu $8,$8,16256\n"
    "addu $2,$2,$8\n"
    "lw $5,0($2)\n"
    "move $4,$16\n"
    "jal func_800B9E9C\n"
    "nop\n"
    "lw $2,216($21)\n"
    ".end func_80071BA0\n.set at\n.set reorder\n");
