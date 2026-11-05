/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075E1C\n.ent func_80075E1C\n"
    "func_80075E1C:\n"
    "sw $0,12($16)\n"
    "sw $0,0($16)\n"
    "lui $17,0x1\n"
    "ori $17,$17,0x3c8\n"
    "lui $16,0x800f\n"
    "addiu $16,$16,19712\n"
    "addu $17,$20,$17\n"
    "lw $2,180($17)\n"
    "move $5,$16\n"
    "lh $4,16($2)\n"
    "lw $2,20($2)\n"
    "jalr $2\n"
    "addu $4,$17,$4\n"
    "move $4,$17\n"
    ".end func_80075E1C\n.set at\n.set reorder\n");
