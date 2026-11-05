/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B9E74\n.ent func_800B9E74\n"
    "func_800B9E74:\n"
    "slti $2,$2,1921\n"
    ".word 0x14400011\n"
    "lui $16,0x800f\n"
    "addiu $16,$16,6880\n"
    "move $4,$16\n"
    "li $5,120\n"
    "move $6,$0\n"
    ".end func_800B9E74\n.set at\n.set reorder\n");
