/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800E5788\n.ent func_800E5788\n"
    "func_800E5788:\n"
    "sb $0,2912($19)\n"
    "addiu $4,$19,2004\n"
    "addiu $5,$19,2620\n"
    "addiu $6,$19,2068\n"
    "jal func_800AD2A8\n"
    "li $7,1\n"
    "jal func_800ADC38\n"
    ".end func_800E5788\n.set at\n.set reorder\n");
