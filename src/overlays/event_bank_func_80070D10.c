/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80070D10\n.ent func_80070D10\n"
    "func_80070D10:\n"
    "addiu $5,$21,184\n"
    "li $6,5432\n"
    "lui $7,0x8007\n"
    "jal func_800AA804\n"
    "addiu $7,$7,2168\n"
    ".end func_80070D10\n.set at\n.set reorder\n");
