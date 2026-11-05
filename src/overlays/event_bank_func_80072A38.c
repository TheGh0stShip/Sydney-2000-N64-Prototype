/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072A38\n.ent func_80072A38\n"
    "func_80072A38:\n"
    "lw $4,104($17)\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    "li $23,3\n"
    "move $5,$2\n"
    "lui $1,0x8007\n"
    "lwc1 $f20,3196($1)\n"
    "move $4,$17\n"
    "mflo $8\n"
    ".end func_80072A38\n.set at\n.set reorder\n");
