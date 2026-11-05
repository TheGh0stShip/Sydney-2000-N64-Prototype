/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076724\n.ent func_80076724\n"
    "func_80076724:\n"
    "jal func_800AB2A4\n"
    "li $6,3\n"
    "move $4,$19\n"
    "sb $0,1213($19)\n"
    "sb $0,3364($16)\n"
    "sb $0,3365($16)\n"
    "sb $0,2840($16)\n"
    "sb $0,2822($16)\n"
    ".end func_80076724\n.set at\n.set reorder\n");
