/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D0B9C\n.ent func_800D0B9C\n"
    "func_800D0B9C:\n"
    "lui $16,0x800f\n"
    "addiu $16,$16,6880\n"
    "move $4,$16\n"
    "li $5,87\n"
    "move $6,$0\n"
    "jal func_8001D4B8\n"
    "li $7,1\n"
    ".end func_800D0B9C\n.set at\n.set reorder\n");
