/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008355C\n.ent func_8008355C\n"
    "func_8008355C:\n"
    "li $5,259\n"
    "move $6,$0\n"
    "jal func_8001D4B8\n"
    "li $7,-1\n"
    "move $4,$16\n"
    "move $17,$2\n"
    "move $5,$17\n"
    "jal func_8001D640\n"
    "move $6,$0\n"
    ".end func_8008355C\n.set at\n.set reorder\n");
