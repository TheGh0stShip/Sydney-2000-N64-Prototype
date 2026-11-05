/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80076094\n.ent func_80076094\n"
    "func_80076094:\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    "addiu $7,$7,3032\n"
    "move $3,$0\n"
    "li $5,2700\n"
    "lw $4,1564($20)\n"
    ".end func_80076094\n.set at\n.set reorder\n");
