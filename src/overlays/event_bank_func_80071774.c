/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071774\n.ent func_80071774\n"
    "func_80071774:\n"
    "addiu $16,$16,1724\n"
    "addu $16,$21,$16\n"
    "move $4,$16\n"
    "li $8,1\n"
    "sw $8,16($29)\n"
    "lw $5,0($3)\n"
    "lw $6,212($21)\n"
    "jal func_800B7130\n"
    "move $7,$0\n"
    "lw $5,216($21)\n"
    "jal func_800BA068\n"
    ".end func_80071774\n.set at\n.set reorder\n");
