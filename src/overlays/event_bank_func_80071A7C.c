/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071A7C\n.ent func_80071A7C\n"
    "func_80071A7C:\n"
    "addu $3,$3,$5\n"
    "sll $2,$3,0x3\n"
    "subu $2,$2,$3\n"
    "and $2,$2,$8\n"
    "sw $2,10004($30)\n"
    "srl $2,$2,0x1e\n"
    "sll $2,$2,0x2\n"
    "lui $8,0x8007\n"
    "addiu $8,$8,16248\n"
    "addu $2,$2,$8\n"
    "lw $5,0($2)\n"
    "j func_800720A0\n"
    "li $6,-1\n"
    ".end func_80071A7C\n.set at\n.set reorder\n");
