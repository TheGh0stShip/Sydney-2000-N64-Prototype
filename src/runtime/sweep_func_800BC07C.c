/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BC07C\n.ent func_800BC07C\n"
    "func_800BC07C:\n"
    "sb $5,0($4)\n"
    "move $2,$5\n"
    "lbu $3,5($4)\n"
    "move $6,$2\n"
    "xor $3,$3,$5\n"
    "sb $3,1($4)\n"
    "move $7,$3\n"
    "lbu $5,5($4)\n"
    "and $2,$2,$3\n"
    "sb $2,3($4)\n"
    "sb $6,5($4)\n"
    "and $5,$5,$7\n"
    "jr $31\n"
    "sb $5,2($4)\n"
    ".end func_800BC07C\n.set at\n.set reorder\n");
