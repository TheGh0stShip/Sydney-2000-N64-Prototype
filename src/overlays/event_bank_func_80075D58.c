/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075D58\n.ent func_80075D58\n"
    "func_80075D58:\n"
    "li $6,40\n"
    "lui $7,0x8007\n"
    "addiu $7,$7,2000\n"
    "sw $18,9904($3)\n"
    "jal func_800AA804\n"
    "sh $17,16($16)\n"
    ".word 0x14400019\n"
    "move $4,$18\n"
    "addiu $5,$16,4\n"
    "li $6,2200\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    ".end func_80075D58\n.set at\n.set reorder\n");
