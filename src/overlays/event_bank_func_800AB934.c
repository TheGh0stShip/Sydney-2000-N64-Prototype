/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AB934\n.ent func_800AB934\n"
    "func_800AB934:\n"
    "addu $4,$19,$2\n"
    "lw $3,328($4)\n"
    "beql $3,$0,L_800AB944\n"
    "li $3,1\n"
    "L_800AB944:\n"
    "lui $2,0x800f\n"
    "sw $3,5104($2)\n"
    "li $2,2\n"
    "sw $0,300($4)\n"
    "j func_80073D80\n"
    "sb $2,285($4)\n"
    ".end func_800AB934\n.set at\n.set reorder\n");
