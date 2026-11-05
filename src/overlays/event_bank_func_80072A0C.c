/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80072A0C\n.ent func_80072A0C\n"
    "func_80072A0C:\n"
    "sw $0,16($29)\n"
    "sw $0,20($29)\n"
    "mflo $8\n"
    "jal func_8001D5D8\n"
    "sra $6,$8,0xf\n"
    "move $4,$17\n"
    "li $5,213\n"
    "move $6,$0\n"
    "li $7,1\n"
    "jal func_8001D4B8\n"
    "sw $16,5032($19)\n"
    ".end func_80072A0C\n.set at\n.set reorder\n");
