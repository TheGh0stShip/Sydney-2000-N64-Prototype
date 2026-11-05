/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80077284\n.ent func_80077284\n"
    "func_80077284:\n"
    "addiu $4,$29,16\n"
    "lw $2,-15760($20)\n"
    "lw $2,2564($2)\n"
    "beql $2,$0,L_80077298\n"
    "sw $0,28($29)\n"
    "L_80077298:\n"
    "lui $5,0x7fff\n"
    "ori $5,$5,0xffff\n"
    "lw $4,11284($19)\n"
    ".end func_80077284\n.set at\n.set reorder\n");
