/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007C04C\n.ent func_8007C04C\n"
    "func_8007C04C:\n"
    "move $4,$16\n"
    "lw $3,104($4)\n"
    "li $2,26213\n"
    "mult $3,$2\n"
    "move $5,$17\n"
    "li $7,75\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "mflo $8\n"
    ".end func_8007C04C\n.set at\n.set reorder\n");
