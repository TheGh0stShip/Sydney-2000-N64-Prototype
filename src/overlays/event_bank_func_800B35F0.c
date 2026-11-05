/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B35F0\n.ent func_800B35F0\n"
    "func_800B35F0:\n"
    "addiu $16,$23,22556\n"
    "move $4,$16\n"
    "li $5,0xffff\n"
    "jal func_8001A330\n"
    "sw $0,22556($23)\n"
    "mfc1 $5,$f20\n"
    "mfc1 $6,$f20\n"
    ".end func_800B35F0\n.set at\n.set reorder\n");
