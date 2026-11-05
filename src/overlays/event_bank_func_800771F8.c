/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800771F8\n.ent func_800771F8\n"
    "func_800771F8:\n"
    "lbu $3,2820($2)\n"
    "lbu $2,2573($5)\n"
    "mult $3,$2\n"
    "move $18,$0\n"
    "move $20,$4\n"
    "lui $19,0x800f\n"
    "mflo $3\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addiu $2,$2,2576\n"
    ".end func_800771F8\n.set at\n.set reorder\n");
