/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BC180\n.ent func_800BC180\n"
    "func_800BC180:\n"
    "li $7,1\n"
    "lw $4,104($16)\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    "move $5,$2\n"
    "move $4,$16\n"
    "mflo $9\n"
    "jal func_8001D640\n"
    "sra $6,$9,0xf\n"
    "j func_80071790\n"
    "nop\n"
    ".end func_800BC180\n.set at\n.set reorder\n");
