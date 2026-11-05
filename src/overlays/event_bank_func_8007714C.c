/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007714C\n.ent func_8007714C\n"
    "func_8007714C:\n"
    "move $4,$17\n"
    "addu $16,$16,$18\n"
    "addiu $17,$18,30684\n"
    "move $4,$17\n"
    "lw $6,28($29)\n"
    "lbu $5,28564($16)\n"
    "jal func_8009D360\n"
    "negu $6,$6\n"
    ".end func_8007714C\n.set at\n.set reorder\n");
