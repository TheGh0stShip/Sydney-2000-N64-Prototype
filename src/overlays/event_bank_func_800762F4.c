/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800762F4\n.ent func_800762F4\n"
    "func_800762F4:\n"
    "jal func_800D6EA0\n"
    "move $4,$16\n"
    "jal func_800AC334\n"
    "move $4,$16\n"
    "li $16,0xd954\n"
    "addu $16,$18,$16\n"
    "jal func_800D771C\n"
    "move $4,$16\n"
    "lw $2,180($16)\n"
    ".end func_800762F4\n.set at\n.set reorder\n");
