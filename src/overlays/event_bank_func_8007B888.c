/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007B888\n.ent func_8007B888\n"
    "func_8007B888:\n"
    "li $3,32767\n"
    "mult $4,$3\n"
    "move $5,$2\n"
    "move $4,$16\n"
    "mflo $8\n"
    "jal func_8001D640\n"
    "sra $6,$8,0xf\n"
    "move $5,$0\n"
    "addiu $6,$29,28\n"
    ".end func_8007B888\n.set at\n.set reorder\n");
