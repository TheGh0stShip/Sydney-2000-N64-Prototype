/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071104\n.ent func_80071104\n"
    "func_80071104:\n"
    "lui $4,0x800f\n"
    "addiu $4,$4,10072\n"
    "addiu $5,$21,200\n"
    "li $6,328\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    "addiu $7,$7,2448\n"
    "lw $5,200($21)\n"
    "jal func_800AAA58\n"
    "li $4,328\n"
    "jal func_8007E264\n"
    "move $4,$2\n"
    "li $5,11\n"
    ".end func_80071104\n.set at\n.set reorder\n");
