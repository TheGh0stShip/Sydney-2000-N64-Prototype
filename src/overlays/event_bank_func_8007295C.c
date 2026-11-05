/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007295C\n.ent func_8007295C\n"
    "func_8007295C:\n"
    "addiu $8,$8,16280\n"
    "addu $2,$2,$8\n"
    "lw $5,0($2)\n"
    "jal func_800B9E9C\n"
    "move $4,$17\n"
    "move $4,$17\n"
    "addiu $5,$29,24\n"
    "move $6,$21\n"
    "jal func_800B9964\n"
    "move $7,$20\n"
    ".end func_8007295C\n.set at\n.set reorder\n");
